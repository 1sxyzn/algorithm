#include <iostream>
#include <vector>

using namespace std;

int main(){
    // 1) 현재 n 번째 잔을 마실 경우
    //      1-1) n-1 번째 잔을 마셨을 경우 == n-3번까지의 최댓 포도주 양과 + n-1, n 잔의 양 (n-2번째를 마시면 연속된 세 잔을 마신 것이므로 제외) == dp[n-3] + v[n-1] + v[n]
    //      1-2) n-1 번째 잔을 마시지 않을 경우 == dp[n-2] + v[n]
    // 2) 현재 n 번째 잔을 마시지 않을 경우 == dp[n-1]

    int n;
    cin>>n;
    vector<int>v(n,0);
    vector<int>dp(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    dp[0] = v[0];
    dp[1] = v[0] + v[1];
    dp[2] = max(max(v[0] + v[2], v[1] + v[2]), dp[1]);
    for(int i=3; i<n; i++){
        dp[i] = max(max(dp[i-3] + v[i-1] + v[i], dp[i-2] + v[i]), dp[i-1]);
    }
    cout<<dp[n-1];
}
