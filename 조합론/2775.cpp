#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<vector<int>>dp(15,vector<int>(15,0));
    for(int i=0; i<15; i++){
        dp[0][i]=i;
        dp[i][1]=1;
    }

    for(int i=1; i<15; i++){
        for(int j=2; j<15; j++){ // 0호는 없고 1호부터 시작 & 1호는 1로 채웠으면서 2호부터 시작 -> j=2
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    int t,k,n;
    cin>>t;
    while(t--){
        cin>>k>>n;
        cout<<dp[k][n]<<'\n';
    }
}
