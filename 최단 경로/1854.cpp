#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>>graph(n+1,vector<int>(n+1,0));
    vector<priority_queue<int>>dist(n+1); // 정답 저장 배열, 내림차순

    int a,b,c;
    while(m--){
        cin>>a>>b>>c;
        graph[a][b]=c;
    }

    // 다익스트라 시작
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q; // 탐색용 큐, 오름차순
    q.push({0,1}); // 1번 도시부터 시작
    dist[1].push(0);

    while(!q.empty()){
        int node = q.top().second;
        int weight = q.top().first;
        q.pop();

        for(int i=1; i<=n; i++){ // 연결된 모든 노드 탐색
            if(graph[node][i]!=0){ // node에서 i로 가는 값이 저장되어 있다면
                if(dist[i].size()<k){ // node에서 i로 가는 경로가 k개 이하 저장되어 있으면
                    dist[i].push(weight + graph[node][i]); // 시작에서 node까지 간 거리 + node에서 i까지 간 거리를 dist[i]에 저장
                    q.push({weight + graph[node][i], i});
                }
                else if(dist[i].top() > weight + graph[node][i]){ // 저장된 경로가 k개이다. 이 땐 가장 큰 값이랑 비교해서, 새 값이 더 작으면 추가하기
                    dist[i].pop();
                    dist[i].push(weight + graph[node][i]);
                    q.push({weight + graph[node][i], i});
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(dist[i].size()==k){
            cout<<dist[i].top()<<'\n'; // 거리는 내림차순이므로 top이 k번째 최단경로임 (q의 밑바닥이 제일 빠른 최단경로)
        }
        else{
            cout<<-1<<'\n';
        }
    }
}
