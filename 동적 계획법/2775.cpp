#include <iostream>
#include <vector>

using namespace std;

int people(vector<vector<int>>&v, int k, int n){
    for(int i=1; i<=n; i++){
        v[0][i]=i;
    }
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            v[i][j]=v[i][j-1]+v[i-1][j]; // 왼쪽 옆집 + 아랫층 집
        }
    }
    return v[k][n];
}

int main(){
    int t,k,n;
    cin>>t;
    while(t--){
        cin>>k>>n;
        vector<vector<int>>apart(k+1,vector<int>(n+1,0));
        cout<<people(apart,k,n)<<'\n';
    }
}
