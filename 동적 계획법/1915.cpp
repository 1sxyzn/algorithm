#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>dp(n,vector<int>(m,0));

    int max=0;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++){
            dp[i][j]=s[j]-'0';

            if(dp[i][j]==1 && i>0 && j>0){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
            if(max < dp[i][j]) max=dp[i][j];
        }
    }
    cout<<max * max;
}
