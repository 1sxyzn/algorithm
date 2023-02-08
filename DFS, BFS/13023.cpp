#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>graph;
vector<bool>visit;
int depth=1;
bool arrive=false;

void dfs(int node, int depth){
    if(depth>=5){
        arrive=true;
        return;
    }
    visit[node]=true;
    for(int i=0; i<graph[node].size(); i++){
        if(!visit[graph[node][i]])
            dfs(graph[node][i],depth+1);
    }
    visit[node]=false;
}

int main(){
    int n, m;
    cin>>n>>m;
    graph.assign(n+1,vector<int>(0));
    visit.assign(n+1,false);
    int s, e;
    for(int i=0; i<m; i++){
        cin>>s>>e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    for(int i=1; i<=n; i++){
        dfs(i,depth);
        if(arrive){
            break;
        }
    }
    if(arrive) cout<<'1';
    else cout<<'0';
}
