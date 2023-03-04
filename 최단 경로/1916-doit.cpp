#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>>graph(n+1,vector<pair<int,int>>(0)); // 그래프 정보 저장
    vector<bool>started(n+1,false); // 해당 노드를 시작점으로 탐색 했었는지 저장
    vector<int>dist(n+1,987654321); // 최단 거리 저장

    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        graph[u].push_back({w,v}); // 비용, 도착 노드 저장
    }

    int start,end;
    cin>>start>>end;

    // 다익스트라 시작
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>q;
    q.push({0,start});
    dist[start]=0;
    while(!q.empty()){
        int node = q.top().second;
        q.pop();

        if(!started[node]){
            started[node]=true;
            for(int i=0; i<graph[node].size(); i++){
                if(dist[node] + graph[node][i].first < dist[graph[node][i].second]){
                    dist[graph[node][i].second] = dist[node] + graph[node][i].first;
                    q.push({dist[graph[node][i].second], graph[node][i].second});
                }
            }
        }
    }
    cout<<dist[end];
}
