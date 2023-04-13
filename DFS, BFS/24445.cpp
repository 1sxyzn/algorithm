#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int>>graph;
vector<int>visit;
int cnt=1;

void bfs(int node){
    queue<int>q;
    q.push(node);
    visit[node]=cnt++;

    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(int i=0; i<graph[f].size(); i++){
            if(visit[graph[f][i]]==0){
                q.push(graph[f][i]);
                visit[graph[f][i]]=cnt++;
            }
        }
    }
}

int main(){
    int n,m,start; cin>>n>>m>>start;
    graph.assign(n+1, vector<int>(0));
    visit.assign(n+1, 0);

    int u,v;
    while(m--){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n; i++) sort(graph[i].begin(), graph[i].end(), greater<>());
    bfs(start);

    for(int i=1; i<=n; i++){
        cout<<visit[i]<<'\n';
    }
}
