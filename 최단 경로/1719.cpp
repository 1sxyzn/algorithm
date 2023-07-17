#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dist(n+1,vector<int>(n+1,987654321));
    vector<vector<int>>ans(n+1, vector<int>(n+1, 0));
    for(int i=0; i<=n; i++) dist[i][i]=0;

    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        dist[u][v] = w;
        dist[v][u] = w;
        ans[u][v] = v;
        ans[v][u] = u;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                    ans[i][j] = ans[i][k];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) cout<<"- ";
            else cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}
