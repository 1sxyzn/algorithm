#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<long long>>dp(n+1,vector<long long>(2,0)); // dp[i][0] = 길이 i인데 끝이 0으로 끝나는 수 갯수
    dp[1][0]=0; // 0 , 이친수 아님
    dp[1][1]=1; // 1 . 이친수 맞음

    for(int i=2; i<=n; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    cout<<dp[n][0]+dp[n][1];
}
