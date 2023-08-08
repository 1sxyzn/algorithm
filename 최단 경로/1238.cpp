#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// 접근 방법 - 왕복을 따로 계산해야함
// 여러 정점에서 x까지의 최솟값 : 일반 그래프에서, x를 다익스트라 돌렸을 때 가장 작은 값
// x에서 여러 정점까지 최솟값 : 역방향그래프에서, x를 다익스트라 돌렸을 땨 가장 작은 값

vector<int> dist_go;
vector<int> dist_come;
vector<bool> visit;
int x;

void dijkstra(vector<vector<pair<int,int>>>graph, vector<int> &dist){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
    dist[x] = 0;
    q.push({0,x});
    while(!q.empty()){
        int node = q.top().second;
        q.pop();

        if(visit[node]) continue;
        visit[node] = true;

        for(int i=0; i<graph[node].size(); i++){
            int new_w = graph[node][i].second;
            int new_node = graph[node][i].first;
            if(dist[new_node] > dist[node] + new_w) {
                dist[new_node] = dist[node] + new_w;
                q.push({dist[new_node], new_node});
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m>>x;
    vector<vector<pair<int,int>>>go(n+1);
    vector<vector<pair<int,int>>>come(n+1);

    int s,e,w;
    while(m--){
        cin>>s>>e>>w;
        go[s].push_back({e,w});
        come[e].push_back({s,w});
    }

    dist_go.assign(n+1,987654321);
    visit.assign(n+1,false);
    dijkstra(go, dist_go);

    dist_come.assign(n+1,987654321);
    visit.assign(n+1,false);
    dijkstra(come, dist_come);

    int MAX = 0;
    for(int i=1; i<=n; i++){
        if(dist_go[i] + dist_come[i] > MAX && i!=x) MAX = dist_go[i] + dist_come[i];
    }

    cout<<MAX<<'\n';
}
