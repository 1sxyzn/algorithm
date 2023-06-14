#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<pair<int,int>>>graph;
vector<bool>visit;
vector<int>dist;

int n,m;
int p,q;
int min_dist = 987654321, ans = -1;
vector<int>house;
vector<int>convin;

void dijkstra(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    for(int i=0; i<q; i++){ // (중요!!!!) 모든 편의점을 시작점으로 처리 -> for(모든 편의점) 다익스트라(편의점[i]) 이렇게 하면 시간초과 남
        pq.push({0, convin[i]});
        dist[convin[i]]=0;
    }

    while(!pq.empty()){
        int cur_n = pq.top().second;
        pq.pop();
        if(visit[cur_n]) continue;
        visit[cur_n] = true;

        for(int i=0; i<p; i++){ // 중간에, 집 후보 인지 check 하고 거리 갱신!! -> 나중에 일괄적으로 check 하면 시간 더 걸림
            if(cur_n == house[i]){
                if(min_dist > dist[cur_n]){
                    min_dist = dist[cur_n];
                    ans = cur_n;
                }
                else if(min_dist == dist[cur_n]) ans = min(ans, cur_n);
            }
        }

        for(int i=0; i<graph[cur_n].size(); i++){
            int next_n = graph[cur_n][i].first;
            int next_w = graph[cur_n][i].second;

            if(dist[next_n] < next_w || dist[next_n] < dist[cur_n]) continue;

            if(dist[next_n] > dist[cur_n] + next_w){
                dist[next_n] = dist[cur_n] + next_w;
                pq.push({dist[next_n], next_n});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    graph.assign(n+1,vector<pair<int,int>>(0));
    visit.assign(n+1,false);
    dist.assign(n+1,987654321);

    int a,b,c;
    while(m--){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    cin>>p>>q;
    house.assign(p,0);
    convin.assign(q,0);
    for(int i=0; i<p; i++) cin>>house[i];
    for(int i=0; i<p; i++) cin>>convin[i];

    dijkstra();

    cout<<ans;
}
