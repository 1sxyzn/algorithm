#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>>graph;
vector<pair<bool,int>>visit;
int cnt=0;

void dfs(int node){
    if(visit[node].first) return;
    cnt++;
    visit[node].first=true;
    visit[node].second=cnt;
    for(int i=0; i<graph[node].size(); i++){
        if(!visit[graph[node][i]].first){
            dfs(graph[node][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,r,u,v;
    cin>>n>>m>>r;
    graph.assign(n+1,vector<int>(0));
    visit.assign(n+1, {false,0});
    for(int i=1; i<=m; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(r);
    for(int i=1; i<=n; i++){
        cout<<visit[i].second<<'\n';
    }
}
