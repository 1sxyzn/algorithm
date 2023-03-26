#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long>dp(n+1,0);
    dp[1]=1; dp[2]=2; // dp[i] = 2*i인 직사각형 채우는 경우의 수

    for(int i=3; i<=n; i++){
        // i번째 칸을 세로 사각형으로 채우는 경우 = dp[i-1], 가로 사각형으로 채우는 경우 = dp[i-2]
        dp[i] = ( dp[i-1] + dp[i-2] ) % 10007;
    }

    cout<<dp[n];
}
