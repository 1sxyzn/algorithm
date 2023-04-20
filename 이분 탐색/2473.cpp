#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long>liq(n,0);
    for(int i=0; i<n; i++) cin>>liq[i];
    sort(liq.begin(), liq.end());

    int ans[3];

    long long min = 9987654321;
    for(int i=0; i<n-2; i++){
        int s = i+1;
        int e = n-1;
        while(s<e){
            long long sum = liq[i]+liq[s]+liq[e];
            if(abs(sum) < abs(min)){
                ans[0] = liq[i];
                ans[1] = liq[s];
                ans[2] = liq[e];
                min = sum;
            }
            if(sum < 0) s++;
            else e--;
        }
    }
    cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2];
}
