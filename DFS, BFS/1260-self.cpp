#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<int>>graph;
vector<bool>visit;

void dfs(int node){
    visit[node]=true;
    cout<<node<<' ';
    for(int i=0; i<graph[node].size(); i++){
        if(!visit[graph[node][i]]) dfs(graph[node][i]);
    }
}

void bfs(int node){
    queue<int>q;
    q.push(node);
    visit[node]=true;

    while(!q.empty()){
        int next = q.front();
        cout<<next<<' ';
        q.pop();
        for(int i=0; i<graph[next].size(); i++){
            if(!visit[graph[next][i]]){
                visit[graph[next][i]]=true;
                q.push(graph[next][i]);
            }
        }
    }
}

int main(){
    int n,m,v;
    cin>>n>>m>>v;
    graph.assign(n+1,vector<int>(0));
    visit.assign(n+1, false);

    int a,b;
    while(m--){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout<<'\n';
    visit.assign(n+1, false);
    bfs(v);
}
