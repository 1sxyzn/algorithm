#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dist;
vector<bool> visit;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    dist.assign(N+1, 987654321);
    visit.assign(N+1,false);
    vector<vector<pair<int,int>>>graph(N+1);
    
    for(int i=0; i<road.size(); i++){
        graph[road[i][0]].push_back({road[i][1],road[i][2]});
        graph[road[i][1]].push_back({road[i][0],road[i][2]});
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>q;
    dist[1]=0;
    q.push({0,1}); // 거리, 마을 번호 저장
    
    while(!q.empty()){
        int node = q.top().second;
        q.pop();
        
        if(visit[node]) continue;
        visit[node]=true;
        
        for(int i=0; i<graph[node].size(); i++){
            int next_node = graph[node][i].first;
            int next_weight = graph[node][i].second;
            if(dist[next_node] > dist[node] + next_weight){
                dist[next_node] = dist[node] + next_weight;
                q.push({dist[next_node], next_node});
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        if(dist[i]<=K){
            answer++;
        }
    }
    
    return answer;
}
