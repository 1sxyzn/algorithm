#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,r;
    cin>>n>>m>>r;
    vector<vector<int>>graph(n+1, vector<int>(n+1,987654321));
    vector<int>item(n+1,0);
    for(int i=1; i<=n; i++){
        graph[i][i]=0;
        cin>>item[i];
    }

    int a,b,l;
    while(r--){
        cin>>a>>b>>l;
        graph[a][b]=l;
        graph[b][a]=l;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]) graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int j=1; j<=n; j++){
            if(graph[i][j] <= m) sum += item[j];
        }
        ans = max(sum, ans);
    }

    cout<<ans;
}
