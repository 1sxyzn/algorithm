#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

queue<int>q;
vector<vector<int>>graph;
vector<int>visit;
int cnt=1;

void bfs(int node){
    q.push(node);
    visit[node]=cnt;
    while(!q.empty()){
        int next=q.front();
        q.pop();
        for(int i=0; i<graph[next].size(); i++){
            if(visit[graph[next][i]]==0){
                cnt++;
                visit[graph[next][i]]=cnt;
                q.push(graph[next][i]);
            }
        }
    }
}

int main(){
    int n,m,r;
    cin>>n>>m>>r;
    graph.assign(n+1,vector<int>(0));
    visit.assign(n+1,0);

    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i=0; i<n; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(r);

    for(int i=1; i<=n; i++){
        cout<<visit[i]<<'\n';
    }
}
