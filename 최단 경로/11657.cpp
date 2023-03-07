#include<iostream>
#include<vector>
#include<climits>
#include<tuple>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<long long>dist;(n+1,LONG_LONG_MAX);
    vector<tuple<int,int,int>>v;

    for(int i=0; i<m; i++){
        int s,e,t;
        cin>>s>>e>>t;
        v.push_back({s,e,t});
    }

    // 벨만포드 시작
    dist[1]=0; // 1번 도시에서 시작
    for(int i=0; i<n-1; i++){ // n개의 노드에서 최대 n-1개의 간선이 생길 수 있으니 n-1번 수행, 만약 n번 돌았는데도 거리 값이 update되면 음수 사이클 생긴 것
        for(int j=0; j<m; j++){ // 모든 간선 다 봐야함. 음수 사이클 없으면 n-1번 반복해도 update 안됨!
            int s = get<0>(v[j]);
            int e = get<1>(v[j]);
            int t = get<2>(v[j]);
            // INF인 경우는 1번에서 방문할 수 없는 노드, 그러므로 거리 계산에 포함 X
            if(dist[s] != LONG_LONG_MAX && dist[e] > dist[s]+t){
                dist[e]=dist[s]+t; // 최단 거리 갱신
            }
        }
    }

    // 음수 사이클 생기는지 확인 (n번째 반복)
    bool cycle=false;
    for(int i=0; i<m; i++){
        int s = get<0>(v[i]);
        int e = get<1>(v[i]);
        int t = get<2>(v[i]);

        if(dist[s] != LONG_LONG_MAX && dist[e] > dist[s]+t){ // n번째 반복했으면 update 그만되어야하는데, 되는 경우는 cycle 있다는 뜻
            cycle=true;
        }
    }

    if(cycle) cout<<-1;
    else{
        for(int i=2; i<=n; i++){
            if(dist[i]==LONG_LONG_MAX) cout<<-1<<'\n';
            else cout<<dist[i]<<'\n';
        }
    }
}
