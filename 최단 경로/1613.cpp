#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>history;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin>>n>>k;
    history.assign(n+1,vector<int>(n+1,-1));
    
    int a,b;
    while(k--){
        cin>>a>>b;
        history[a][b] = 1;
    }

    // floyd
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(history[i][k]==1 && history[k][j]==1){
                    history[i][j]=1;
                }
            }
        }
    }

    int s;
    cin>>s;
    while(s--){
        cin>>a>>b;
        if(history[a][b]==1) cout<<-1<<'\n';
        else if(history[b][a]==1) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
}
