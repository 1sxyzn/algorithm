#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>graph(n+1);
    vector<int>dist(n+1,987654321);
    vector<bool>visit(n+1,false);

    int a,b,c;
    while(m--){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>q;
    q.push({0,1});
    dist[1]=0;
    while(!q.empty()){
        int node = q.top().second;
        q.pop();

        if(visit[node]) continue;
        visit[node] = true;
        
        for(int i=0; i<graph[node].size(); i++){
            int next = graph[node][i].first;
            int n_w = graph[node][i].second;
            if(dist[next] > dist[node] + n_w) {
                dist[next] = dist[node] + n_w;
                q.push({dist[next], next});
            }
        }
    }
    cout<<dist[n];
}
