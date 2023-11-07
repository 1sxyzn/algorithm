#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 15746; // 맨 앞이 1로 올 때 경우의 수 + 맨 앞이 00으로 올 때 경우의 수
    }
    cout<<dp[n];
}
