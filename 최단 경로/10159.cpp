#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n+1, vector<int>(n+1,0));

    while(m--){
        int s,e;
        cin>>s>>e;
        v[s][e]=1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(v[i][k]==1 && v[k][j]==1) v[i][j]=1;
            }
        }
    }

    for(int i=1; i<=n; i++){
        int ans = 0;
        for(int j=1; j<=n; j++){
            if(i!=j && (v[i][j] == 0 && v[j][i] == 0)) ans++;
        }
        cout<<ans<<'\n';
    }
}
