#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>graph;
vector<bool>visit;

void dfs(int node){
    if(visit[node]) return;
    visit[node]=true;
    for(int i=0; i<graph[node].size(); i++){
        if(!visit[graph[node][i]]) dfs(graph[node][i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, conn=0;
    cin>>n>>m;
    graph.assign(n+1,vector<int>(0));
    visit.assign(n+1, false);

    int s, e;
    for(int i=1; i<=m ; i++){
        cin>>s>>e;
        graph[s].push_back(e); // 방향 없는 그래프이므로
        graph[e].push_back(s); // 양방향으로 저장
    }

    for(int i=1; i<=n; i++){
        if(!visit[i]){
            conn++;
            dfs(i);
        }
    }
    cout<<conn;
}
