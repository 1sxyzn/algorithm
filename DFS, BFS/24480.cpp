#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>>graph;
vector<int>visit;
int cnt=1;

void dfs(int node){
    visit[node]=cnt;
    cnt++;
    for(int i=0; i<graph[node].size(); i++){
        if(visit[graph[node][i]]==0){
            dfs(graph[node][i]);
        }
    }
}

int main(){
    int n,m,start;
    cin>>n>>m>>start;
    graph.assign(n+1,vector<int>(0));
    visit.assign(n+1, 0);

    int u,v;
    while(m--){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end(), greater<>());
    }

    dfs(start);

    for(int i=1; i<=n; i++){
        cout<<visit[i]<<'\n';
    }
}
