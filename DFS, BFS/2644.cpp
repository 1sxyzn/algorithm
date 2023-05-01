#include<iostream>
#include<vector>

using namespace std;

int n, m, s, e;
vector<vector<int>>graph;
vector<int>visit;

void dfs(int node){
    if(node == e) return;
    for(int i=0; i<graph[node].size(); i++){
        if(visit[graph[node][i]]==-1) {
            visit[graph[node][i]] = visit[node]+1;
            dfs(graph[node][i]);
        }
    }
}

int main(){
    cin>>n>>s>>e>>m;
    graph.assign(n+1,vector<int>(0));
    visit.assign(n+1, -1);
    int x,y;
    while(m--){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    visit[s]=0;
    dfs(s);

    cout<<visit[e];
}
