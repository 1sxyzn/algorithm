#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

vector<bool>visit;
vector<int>dist;
int x_y, y_z, x_z;

int dijkstra(int start, int end, vector<vector<pair<int, int>>>graph, int pass){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
    q.push({0,start});
    dist[start]=0;
    while(!q.empty()){
        int cur_n = q.top().second;
        q.pop();
        if(visit[cur_n]) continue;
        visit[cur_n] = true;

        for(int i=0; i<graph[cur_n].size(); i++){
            int next_n = graph[cur_n][i].first;
            int next_w = graph[cur_n][i].second;
            if (dist[next_n] < next_w || next_n == pass || cur_n == pass) continue; // 시간 줄이기 & 특정 노드 피하기

            if(dist[next_n] > dist[cur_n] + next_w){
                dist[next_n] = dist[cur_n] + next_w;
                q.push({dist[next_n], next_n});
            }
        }
    }
    return dist[end];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>graph(n+1, vector<pair<int,int>>(0));
    visit.assign(n+1,false);
    dist.assign(n+1,INT_MAX);

    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }

    int x,y,z; // 시작, 중간, 도착
    cin>>x>>y>>z;

    //-------------------------------------
    // y를 거쳐가는 경우 == x to y 최단경로 + y to z 최단경로
    x_y = dijkstra(x, y,graph, 0);

    // 초기화
    visit.assign(n+1,false);
    dist.assign(n+1,INT_MAX);

    y_z = dijkstra(y, z, graph, 0);
    if(x_y >= INT_MAX || y_z >= INT_MAX) cout<<-1<<' '; // 여기 때문에 틀렸습니다 떴었음!
    // 원랜 x_y + y_z >= int_max 인지 체크했었는데, 그게 아니라 각각의 변수가 int_max 이상인지 확인해줘야 범위 초과 X
    else cout<<x_y + y_z<<' ';

    // 초기화
    visit.assign(n+1,false);
    dist.assign(n+1,INT_MAX);

    //-------------------------------------
    // y를 피해가는 경우
    x_z = dijkstra(x, z, graph, y);
    if(x_z >= INT_MAX) cout<<-1<<' ';
    else cout<<x_z<<' ';
}
