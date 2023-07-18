#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<vector<pair<int,int>>> graph;
vector<bool>visit;
vector<int>dist_jh;
vector<int>dist_sh;
int n, m;

void dijkstra(int start, vector<int>& dist){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
    dist[start] = 0;
    q.push({0, start});

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
    cin>>n>>m;
    graph.assign(n+1, vector<pair<int,int>>(0));

    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    
    int jh,sh;
    cin>>jh>>sh;
    visit.assign(n+1,false);
    dist_jh.assign(n+1,987654321);
    dijkstra(jh, dist_jh);

    visit.assign(n+1,false);
    dist_sh.assign(n+1,987654321);
    dijkstra(sh, dist_sh);

    vector<pair<int,int>>ans; // 지헌이로부터의 거리, 
    int MIN = 987654321;
    for(int i=1; i<=n; i++){
        if(i != jh && i != sh){
            MIN = min(MIN, dist_jh[i] + dist_sh[i]);
        }
    }

    for(int i=1; i<=n; i++){
        if(dist_jh[i] + dist_sh[i] == MIN && dist_jh[i] <= dist_sh[i] && (i != jh && i != sh)){
            ans.push_back({dist_jh[i], i});
        }
    }

    if(ans.size()==0) cout<<-1;
    else {
        sort(ans.begin(), ans.end());
        cout<<ans[0].second<<'\n';
    }
}
