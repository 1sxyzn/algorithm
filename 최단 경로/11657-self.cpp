#include<iostream>
#include<vector>
#include<tuple>
#include<climits>

using namespace std;

/*
 * 벨만 포드는 언제 사용?
 * 가중치가 음수인 경우의 최단 경로를 구할 때.
 * 음수 사이클을 판별할 수 있음
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<long long> dist(n+1,LONG_LONG_MAX);
    vector<tuple<int,int,int>> graph;

    int a,b,c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        graph.push_back({a,b,c});
    }

    dist[1]=0; // 1번 도시에서 시작

    // 벨만 포드
    int check = n-1;
    int s,e,w;
    // n번 이상을 돌릴 때, 사이클 없으면 값이 그대로인데 사이클 있으면 계속 값이 변함. 그래서 일단 n-1번 돌리고 한 번 더 돌리면서 값이 변하나 보자...
    // ( -> 노드가 n개면 최대 n-1개의 간선이 생김)
    while(check--){
        for(int i=0; i<m; i++){
            s = get<0>(graph[i]);
            e = get<1>(graph[i]);
            w = get<2>(graph[i]);

            if(dist[s] != LONG_LONG_MAX && dist[e] > dist[s] + w) dist[e] = dist[s] + w;
        }
    }

    // 음수 사이클 판별
    bool cycle = false;

    for(int i=0; i<m; i++){ // n번째 반복 -> 여기서 값이 변하면 cycle이 생겼다는 뜻임
        s = get<0>(graph[i]);
        e = get<1>(graph[i]);
        w = get<2>(graph[i]);

        if(dist[s] != LONG_LONG_MAX && dist[e] > dist[s] + w) cycle = true;
    }

    if(!cycle){
        for(int i=2; i<=n; i++){
            if(dist[i] == LONG_LONG_MAX) cout<<-1<<'\n';
            else cout<<dist[i]<<'\n';
        }
    }
    else{
        cout<<-1;
    }
}
