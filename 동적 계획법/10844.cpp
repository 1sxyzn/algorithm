#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<long long>>dp(n+1,vector<long long>(10,1));
    // dp[i][j] = 길이가 i인데 마지막이 j로 끝나는 계단수, dp[1][k]는 무조건 1이라 일단 1로 초기화 함
    // 근데 0으로 시작하는건 계산수가 아니니 dp[1][0]=0;
    dp[1][0]=0;

    for(int i=2; i<=n; i++){
        dp[i][0]=dp[i-1][1];
        dp[i][9]=dp[i-1][8];
        for(int j=1; j<=8; j++){
            dp[i][j] = ( dp[i-1][j-1] + dp[i-1][j+1] ) % 1000000000;
        }
    }

    long long sum=0;
    for(int i=0; i<10; i++){
        sum += dp[n][i];
        // sum += dp[n][i] % 1000000000; 하면 틀렸습니다!
        // sum = (sum + dp[n][i]) % 10 억이 되어야 하는데
        // sum = sum + (dp[n][i] % 10억) 의 형태가 될 수도 있음.
        // 이 경우 sum의 결과 값이 10억을 넘길 수도 있고 그러면 답이 틀림
    }

    cout<<sum % 1000000000;
}
