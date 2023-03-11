#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>friends(n+1,vector<int>(n+1,987654321));
    for(int i=0; i<=n; i++){
        friends[i][i]=0;
    }

    int a,b;
    while(m--){
        cin>>a>>b;
        friends[a][b]=1;
        friends[b][a]=1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                friends[i][j] = min(friends[i][j], friends[i][k]+friends[k][j]);
            }
        }
    }

    int min = 98764321;
    int ans = -1;
    for(int i=1; i<=n; i++){
        int temp=0;
        for(int j=1; j<=n; j++){
            temp+=friends[i][j];
        }
        if(min>temp){
            ans=i;
            min=temp;
        }
    }
    cout<<ans;
}
