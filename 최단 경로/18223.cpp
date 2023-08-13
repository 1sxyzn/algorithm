#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<pair<int,int>>>graph;
vector<int>dist_min; // 민준이 위치에서 각 정점 까지의 최단거리
vector<int>dist_gun; // 건우 위치에서 각 정점 까지의 최단거리
vector<bool>visit;
const int INF = 100000000;
int v,e,p;

void dijkstra(int start, vector<int>& dist){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>q;
    q.push({0,start});
    dist[start]=0;

    while(!q.empty()){
        int node = q.top().second;
        q.pop();
        if(visit[node]) continue;
        visit[node] = true;

        for(int i=0; i<graph[node].size(); i++){
            int next = graph[node][i].first;
            int next_w = graph[node][i].second;
            if(dist[next] > dist[node] + next_w){
                dist[next] = dist[node] + next_w;
                q.push({dist[next], next});
            }
        }
    }
}

int main(){
    cin>>v>>e>>p;
    graph.assign(v+1,vector<pair<int,int>>(0));
    int a,b,c;
    while(e--){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    visit.assign(v+1,false);
    dist_min.assign(v+1,INF);
    dijkstra(1,dist_min);

    visit.assign(v+1,false);
    dist_gun.assign(v+1,INF);
    dijkstra(p,dist_gun);

    if(dist_min[p] + dist_gun[v] == dist_min[v]) cout<<"SAVE HIM";
    else cout<<"GOOD BYE";
}
