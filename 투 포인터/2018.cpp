#include<iostream>

using namespace std;

int main(){
    int n, ans=1; // 자기 자신 포함
    cin>>n;
    int start=1, end=1; // 포인터
    int sum =1; // start부터 end까지의 합
    while(end<n){
        if(sum<=n){
            if(sum==n) ans++;
            end++;
            sum+=end;
        }
        else{
            sum-=start;
            start++;
        }
    }
    cout<<ans;
}
