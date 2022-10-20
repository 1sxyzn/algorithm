#include<iostream>
#include<vector>
using namespace std;
const int size=5000;
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,size);
    dp[3]=dp[5]=1;
    for(int i=6; i<=n; i++){
        dp[i]=min(dp[i-3], dp[i-5])+1;
    }
    if(dp[n]>=size) cout<<-1;
    else cout<<dp[n];
}
