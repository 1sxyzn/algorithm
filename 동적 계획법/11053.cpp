#include<iostream>
#include<vector>

using namespace std;

int LIS(int n, vector<int> num){
    vector<int>dp(n,1);
    int lis=1; //가장 긴 증가하는 부분 수열 저장

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(num[i]>num[j]){ 
                dp[i]=max(dp[j]+1, dp[i]); // 해당 수를 최댓값으로, 가장 긴 증가하는 부분 수열 구하기
                lis = max(lis, dp[i]); //전체 중에서 가장 긴 증가하는 부분 수열 갱신하기
            }
        }
    }
    return lis;
}

int main(){
    int n;
    cin>>n;
    vector<int>num(n,0);
    for(int i=0; i<n; i++)
        cin>>num[i];

    cout<<LIS(n, num)<<'\n';
}
