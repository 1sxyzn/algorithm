#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m,s,e;
vector<vector<int>>graph;
vector<int>visit;

void bfs(int node){
    queue<int>q;
    q.push(node);
    visit[node]=0;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0; i<graph[now].size(); i++){
            if(visit[graph[now][i]]==-1){
                visit[graph[now][i]] = visit[now] + 1;
                q.push(graph[now][i]);
            }
        }
    }
}

int main(){
    cin>>n>>s>>e>>m;
    graph.assign(n+1, vector<int>(0));
    visit.assign(n+1, -1);
    int x,y;
    while(m--){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bfs(s);
    cout<<visit[e];
}
