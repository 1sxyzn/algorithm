#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>>graph;
vector<int>visit;

void bfs(int node){
    queue<int>q;
    q.push(node);
    visit[node]++;
    while(!q.empty()){
        int next=q.front();
        q.pop();
        for(int i=0; i<graph[next].size(); i++){
            if(visit[graph[next][i]]==-1){
                q.push(graph[next][i]);
                visit[graph[next][i]]=visit[next]+1;
            }
        }
    }
}

int main(){
    // 도시의 개수 N, 도로의 개수 M, 거리 정보 dist, 출발 도시의 번호 start
    int n,m,dist,start;
    cin>>n>>m>>dist>>start;
    graph.assign(n+1,vector<int>(0));
    visit.assign(n+1,-1);
    int a,b;
    while(m--){
        cin>>a>>b;
        graph[a].push_back(b);
    }

    bfs(start);

    bool flag=false;
    for(int i=1; i<=n; i++){
        if(visit[i]==dist){
            cout<<i<<'\n';
            flag=true;
        }
    }
    if(!flag) cout <<-1;
}
