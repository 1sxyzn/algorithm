#include<iostream>
#include<queue>

using namespace std;

int ans=0;
vector<vector<int>>graph;
vector<bool>visit;

void bfs(int node){
    queue<int>q;
    if(!visit[node]){
        ans++;
        visit[node]=true;
        q.push(node);
    }
    else return;

    while(!q.empty()){
        int f = q.front();
        q.pop(); // 이거 깜빡했었음 ..^^
        for(int i=0; i<graph[f].size(); i++){
            if(!visit[graph[f][i]]){
                q.push(graph[f][i]);
                visit[graph[f][i]]=true;
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    graph.assign(n+1,vector<int>(0));
    visit.assign(n+1,false);

    int u,v;
    while(m--){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        bfs(i);
    }
    cout<<ans;
}
