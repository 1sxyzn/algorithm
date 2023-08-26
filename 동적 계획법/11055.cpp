#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int a;
    cin>>a;
    vector<int>arr(a,0);
    vector<int>dp(a,0);
    for(int i=0; i<a; i++){
        cin>>arr[i];
        dp[i]=arr[i];
    }
    for(int i=1; i<a; i++){
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[j]+arr[i], dp[i]);
            }
        }
    }

    sort(dp.begin(), dp.end(), greater<>());
    cout<<dp[0];
}
