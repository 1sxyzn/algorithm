#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// 1. start -> a -> b -> end
// 2. start -> b -> a -> end
// 중 최단 거리를 구하자
// start에서 다익스트라 한 번, a 에서 다익스트라 한 번, b 에서 다익스트라 한 번 => 총 3번 돌림

// INF 를 20억 으로 설정했더니 틀렸습니다 뜸 INF + INF + INF 를 했을 때 정수 범위를 넘으면 안되므로 20억/3 의 값, 혹은
// 간선의 수 200000 * 가중치 최댓 값 1000 = 200000000 을 INF로 잡기

vector<vector<pair<int,int>>>graph;
vector<int>visit;
vector<int>dist_start;
vector<int>dist_a;
vector<int>dist_b;
const int INF = 200000000;

void dijkstra(int start, vector<int>&dist){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>q;
    dist[start] = 0;
    q.push({0,start});
    while(!q.empty()){
        int node = q.top().second;
        q.pop();

        if(visit[node]) continue;
        visit[node] = true;

        for(int i=0; i<graph[node].size(); i++){
            int next = graph[node][i].first;
            int weight = graph[node][i].second;
            if(dist[next] > dist[node] + weight){
                dist[next] = dist[node] + weight;
                q.push({dist[next], next});
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    graph.assign(n+1,vector<pair<int,int>>(0));

    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    int a, b;
    cin>>a>>b;

    // start에서 다익스트라 한 번
    visit.assign(n+1,false);
    dist_start.assign(n+1,INF);
    dijkstra(1, dist_start);

    // a에서 다익스트라 한 번
    visit.assign(n+1,false);
    dist_a.assign(n+1,INF);
    dijkstra(a, dist_a);

    // b에서 다익스트라 한 번
    visit.assign(n+1,false);
    dist_b.assign(n+1,INF);
    dijkstra(b, dist_b);

    int ans = min(INF, min(dist_start[a] + dist_a[b] + dist_b[n], dist_start[b] + dist_b[a] + dist_a[n]));
    if(ans == INF) cout<<-1;
    else cout<<ans;
}
