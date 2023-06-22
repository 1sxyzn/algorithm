#include<iostream>
#include<vector>

using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n+1, vector<int>(n+1,987654321));
    for(int i=0; i<=n; i++) graph[i][i]=0;

    int a,b;
    while(m--){
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]) graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    int ans1 = 0, ans2 = 0, ans = 987654321;
    for(int i=1; i<=n; i++){ // 건물 1
        for(int j=i+1; j<=n; j++){ // 건물 2
            int temp = 0;
            for(int k=1; k<=n; k++){
                if(k!=i && k!=j) temp += min(graph[i][k], graph[j][k]);
            }
            if(temp < ans){
                ans = temp;
                ans1 = i;
                ans2 = j;
            }
        }
    }
    cout<<ans1<<' '<<ans2<<' '<<ans*2;
}
