#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    int start=1;
    int end=k;
    int ans;

    while(start<=end){
        int mid=(start+end)/2;
        int under=0; // 임의의 수 mid 보다 작은 수

        for(int i=1; i<=n; i++){
            under+=min(mid/i, n);
        }
        if(under<k) start=mid+1;
        else{
            end=mid-1;
            ans=mid;
        }
    }
    cout<<ans;
}
