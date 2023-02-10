#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<vector<int>>graph;
vector<bool>visit;

void dfs(int node){
    if(visit[node]) return;
    visit[node]=true;
    cout<<node<<' ';
    for(int i=0; i<graph[node].size(); i++){
        if(!visit[graph[node][i]]){
            dfs(graph[node][i]);
        }
    }
}

void bfs(int node){
    queue<int>q;
    q.push(node);
    visit[node]=true;

    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout<<cur<<' ';
        for(int i=0; i<graph[cur].size(); i++){
            if(!visit[graph[cur][i]]){
                visit[graph[cur][i]]=true;
                q.push(graph[cur][i]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,v;
    cin>>n>>m>>v;
    graph.assign(n+1,vector<int>(0));
    visit.assign(n+1,false);

    int s,e;
    for(int i=1; i<=m; i++){ // 인접 리스트로 구현
        cin>>s>>e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    for(int i=1; i<=n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v);
    cout<<'\n';
    visit.assign(n+1,false);
    bfs(v);
}
