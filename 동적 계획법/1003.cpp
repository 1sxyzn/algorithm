#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>dp1(n+1,0);
        vector<int>dp0(n+1,0);
        dp1[0] = 0; dp1[1] = 1;
        dp0[0] = 1; dp0[1] = 0;
        for(int i=2; i<=n; i++){
            dp1[i] = dp1[i-1] + dp1[i-2];
            dp0[i] = dp0[i-1] + dp0[i-2];
        }
        cout<<dp0[n]<<' '<<dp1[n]<<'\n';
    }
}
