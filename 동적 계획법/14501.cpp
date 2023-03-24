#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int>day(n+1,0);
    vector<int>pay(n+1,0);
    vector<int>dp(n+2,0); // dp[n+1] 접근 예정..,,
    for(int i=1; i<=n; i++){
        cin>>day[i]>>pay[i];
    }
    for(int i=n; i>0; i--){
        if(i+day[i]>n+1){ // 현재 일을 수행했을 때 퇴사일 넘어가면 skip..
            dp[i]=dp[i+1];
        }
        else { // 일이 퇴사일 안쪽에 끝나서 수행 가능할 경우
            // 해당 일을 skip 해야 수익이 더 높은 경우 vs 해당 일을 했을 때 수익 (현재 일 했을 때 수익 + 끝나는 날 기점으로 일을 재개했을 때 벌 수 있는 수익)이 더 높은 경우
            dp[i] = max(dp[i + 1], pay[i] + dp[i + day[i]]);
        }
    }
    cout<<dp[1];
}
