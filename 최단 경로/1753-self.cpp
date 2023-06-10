
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, k; // 정점, 간선, 시작 정점
    cin>>v>>e>>k;
    vector<vector<pair<int,int>>>graph(v+1,vector<pair<int,int>>(0));
    vector<int>dist(v+1,987654321);
    vector<bool>visit(v+1,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;

    int start, end, w;
    while(e--){
        cin>>start>>end>>w;
        graph[start].push_back({end, w});
    }

    pq.push({0, k}); // 거리, 노드
    dist[k]=0;

    while(!pq.empty()){
        pair<int,int> cur = pq.top();
        pq.pop();
        int end_node = cur.second;
        if(visit[end_node]) continue;
        visit[end_node] = true;

        for(int i=0; i<graph[end_node].size(); i++){
            int next_node = graph[end_node][i].first;
            int next_weight = graph[end_node][i].second;

            if(dist[next_node] > dist[end_node] + next_weight){
                dist[next_node] = dist[end_node] + next_weight;
                pq.push({ dist[next_node], next_node});
            }
        }
    }

    for(int i=1; i<=v; i++){
        if(visit[i]) cout<<dist[i]<<'\n';
        else cout<<"INF"<<'\n';
    }
}
