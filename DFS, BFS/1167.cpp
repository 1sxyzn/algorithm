#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int>dist;
vector<vector<pair<int,int>>>graph;

void bfs(int idx){
    queue<int>q;
    q.push(idx);
    dist[idx]=0;

    while(!q.empty()){
        int new_node=q.front();
        q.pop();
        for(int i=0; i<graph[new_node].size(); i++){
            if(dist[graph[new_node][i].first]==-1){
                dist[graph[new_node][i].first]+=(1+graph[new_node][i].second+dist[new_node]);
                q.push(graph[new_node][i].first);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    graph.assign(n+1,vector<pair<int,int>>(0));
    dist.assign(n+1,-1);

    int s;
    for(int i=1; i<=n; i++){
        cin>>s;
        int e=0, val;
        while(true){
            cin>>e;
            if(e==-1) break;
            cin>>val;
            graph[s].push_back(make_pair(e,val));
        }
    }
    bfs(1); // 임의의 점으로 시작
    int max_dist_idx=1;
    for(int i=2; i<=n; i++){
        if(dist[i]>dist[max_dist_idx]) max_dist_idx=i;
    }
    dist.assign(n+1,-1); // 거리 초기화
    bfs(max_dist_idx);
    sort(dist.begin(), dist.end());
    cout<<dist[n];
}
