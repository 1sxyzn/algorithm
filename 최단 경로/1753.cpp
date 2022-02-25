#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int INF = 1e5 * 2;

vector<int> dijkstra(int vertex, int k, vector<vector<pair<int,int>>> &graph){
    vector<int> dist(vertex+1, INF); //거리 저장할 벡터, inf로 초기화
    // 우선순위 큐 오름차순, pair의 first는 시작점부터의 거리, second는 정점 거리를 저장할 것임
    //거리가 짧은 것 부터 정렬을 하고싶으므로 거리을 큐의 첫 번째 요소로 두어야한다.
    priority_queue<pair<int,int>,vector<pair<int, int>>,greater<>> pq;

    dist[k]=0;
    pq.push({0,k});

    while(!pq.empty()){
        int v=pq.top().second;
        int w=pq.top().first;
        pq.pop();

        if(w>dist[v]) //중복을 방지하기 위해 (시간 단축)
            continue;

        for(int i=0; i < graph[v].size(); i++){ //정점 v에 연결된 노드들 모두 확인
            int next_v=graph[v][i].first; //정점 v의 i번째 연결된 노드
            int next_w=w+graph[v][i].second; //출발점에서 v까지의 가중치 + v에서 i번째 연결된 노드까지의 가중치
            if(dist[next_v] > next_w){ //중간을 거쳐가는게 더 빠르다면
                dist[next_v]=next_w;
                pq.push({next_w,next_v});
            }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int vertex,edge,k,u,v,w;
    cin>>vertex>>edge>>k;
    vector<vector<pair<int,int>>> graph(vertex+1, vector<pair<int,int>>(0));
    while(edge--){
        cin>>u>>v>>w;
        graph[u].emplace_back(v,w); //.push_back(make_pair(v,w))와 같음. (u->v인 경로의 가중치는 w라는 뜻)
    }

    vector<int> ans = dijkstra(vertex, k, graph);

    for(int i=1; i<=vertex; i++){
        if(ans[i]==INF)
            cout<<"INF"<<'\n';
        else
            cout<<ans[i]<<'\n';
    }
}
