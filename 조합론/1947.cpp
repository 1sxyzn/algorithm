#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n; cin>>n;
    vector<long long>dp(n+1,0);
    dp[2]=1; // 0사람, 1사람이 선물 주고 받을 수 x -> 0 && 2사람은 선물 서로에게만 주고 받을 수 o -> 1
    for(int i=3; i<=n; i++){
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]) % 1000000000; // n-1 사람에게 줄 수 있음 * (준 사람이 아닌 사람에게 받을 때 + 준 사람에게 받을 때)
    }
    cout<<dp[n];
}
