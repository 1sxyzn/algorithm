#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a,b,t;
    vector<vector<int>>graph(n+1,vector<int>(n+1,987654321));
    while(m--){
        cin>>a>>b>>t;
        graph[a][b]=t;
    }
    for(int i=1; i<=n; i++) graph[i][i]=0;

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]) graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    int k;
    cin>>k;
    vector<int> f(k,0);
    for(int i=0; i<k; i++){
        cin>>f[i];
    }

    vector<pair<int,int>>ans(n, {0,0});
    for(int i=1; i<=n; i++){
        int dist = 0;
        for(int j=0; j<k; j++){
            dist = max(graph[f[j]][i]+graph[i][f[j]], dist);
        }
        ans[i-1] = {dist,i};
    }

    sort(ans.begin(), ans.end());
    int val = ans[0].first;
    for(int i=0; i<ans.size(); i++){
        if(ans[i].first == val){
            cout<<ans[i].second<<' ';
        }
        else break;
    }
}
