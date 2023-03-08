#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n+1,vector<int>(n+1,1e9));
    for(int i=1; i<=n; i++){
        v[i][i]=0;
    }

    int a,b,c;
    while(m--){
        cin>>a>>b>>c;
        if(v[a][b]>c) v[a][b]=c;
    }

    // 플로이드
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(v[i][j]>v[i][k]+v[k][j]){
                    v[i][j]=v[i][k]+v[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(v[i][j]==1e9) cout<<0<<' ';
            else cout<<v[i][j]<<' ';
        }
        cout<<'\n';
    }
}
