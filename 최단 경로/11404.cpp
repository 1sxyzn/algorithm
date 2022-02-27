#include<iostream>
#include<vector>

using namespace std;
const int INF = 1e7; // INF 값 주의, 다른 곳을 거쳐서 갈 경우 100000를 넘을 수 있음

vector<vector<int>> floydWarshall(int n, vector<vector<int>> graph){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                graph[i][j]=min(graph[i][j], graph[i][k]+graph[k][j]); //i->j와 i->k->j를 비교해서 최단 경로 저장
            }
        }
    }
    return graph;
}

int main(){
    int n,m,a,b,c;
    cin>>n>>m;
    vector<vector<int>>graph(n+1,vector<int>(n+1,INF));
    for(int i=1; i<=n; i++){
        graph[i][i]=0; //자기자신으로 가는 경로는 0
    }
    while(m--){
        cin>>a>>b>>c;
        graph[a][b]=min(graph[a][b],c); //중복 간선이 들어올 수 있으므로 최솟값 이용
    }

    vector<vector<int>> short_path = floydWarshall(n, graph);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) {
            if(short_path[i][j]==INF)
                cout<<'0'<<' ';
            else
                cout << short_path[i][j] << ' ';
        }
        cout<<'\n';
    }
}
