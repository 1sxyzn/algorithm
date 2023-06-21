#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v,e;
    cin>>v>>e;
    vector<vector<int>>graph(v+1, vector<int>(v+1,987654321));

    int a,b,c;
    while(e--){
        cin>>a>>b>>c;
        graph[a][b] = c;
    }

    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]) graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    int ans = 987654321;
    for(int i=1; i<=v; i++){
        ans = min(ans, graph[i][i]);
    }

    if(ans >= 987654321) cout<<-1;
    else cout<<ans;
}
