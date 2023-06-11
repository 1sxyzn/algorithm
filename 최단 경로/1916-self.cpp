#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m; // 도시, 버스 갯수
    vector<vector<pair<int,int>>>graph(n+1, vector<pair<int,int>>(0));
    vector<int>dist(n+1,987654321);
    vector<bool>visit(n+1,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }

    int start, end;
    cin>>start>>end;
    pq.push({0,start});
    dist[start]=0;

    while(!pq.empty()){
        pair<int,int> cur = pq.top();
        pq.pop();
        int cur_node = cur.second;
        if(visit[cur_node]) continue;
        visit[cur_node] = true;

        for(int i=0; i<graph[cur_node].size(); i++){
            int next_node = graph[cur_node][i].first;
            int next_weight = graph[cur_node][i].second;

            if(dist[next_node] > dist[cur_node] + next_weight){
                dist[next_node] = dist[cur_node] + next_weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    cout<<dist[end];
}
