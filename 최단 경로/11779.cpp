//1916.cpp에서 코드 추가
//다익스트라 + 역추적

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e8;

vector<int> back(int e, vector<int> path){
    vector<int> result;
    while(e){
        result.push_back(e);
        e=path[e];
    }
    return result;
}

int dijkstra(int n, int s, int e, vector<vector<pair<int,int>>> graph, vector<int> &path){ //다익스트라
    vector<int> dist(n+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; //작은 것 부터

    dist[s]=0; //자기자신으로 가는 거리 = 0
    pq.push({0,s}); // pair pq는 first 기준으로 정렬하는데 가중치 작은 것이 필요하므로 가중치를 first에 두기

    while(!pq.empty()){
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(weight > dist[node]) //재방문 방지, 시간 단축
            continue;

        for(int i=0; i<graph[node].size(); i++){
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;

            if(dist[next_node] > next_weight){ //더 빠른 경로면 갱신
                dist[next_node] = next_weight;
                path[next_node] = node; //이전 노드 저장, node -> next_node 경로로 갔으니 역추적시 next_node -> node 로 추적함
                pq.push({next_weight,next_node});
            }
        }
    }
    return dist[e];
}

int main(){
    int n,m,a,b,c,s,e;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1, vector<pair<int,int>>(0));
    vector<int> path(n+1,0);//다른 역추적과 달리 0으로 초기화 가능. n>=1 이므로

    while(m--){
        cin>>a>>b>>c;
        graph[a].push_back(make_pair(b,c)); //a에서 b로 가는 경로의 가중치는 c이다.
    }

    cin>>s>>e;

    cout<<dijkstra(n,s,e,graph,path)<<'\n';

    vector<int> result = back(e,path);

    cout<<result.size()<<'\n';

    for(int i=result.size()-1; i>=0; i--){
        cout<<result[i]<<' ';
    }

}
