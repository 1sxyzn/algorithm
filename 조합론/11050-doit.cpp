#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,k; cin>>n>>k;
    vector<vector<int>>pascal(11,vector<int>(11,0)); // 파스칼의 삼각형
    for(int i=0; i<=n; i++){
        pascal[i][0]=1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1]; // 5C3 = 4C3 + 4C2 성립
        }
    }

    cout<<pascal[n][k];
}
