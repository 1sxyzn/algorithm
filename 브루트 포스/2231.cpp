#include<iostream>

using namespace std;

int main() {
    int n, i, temp, sum;
    cin>>n;
    //브루트 포스
    for(i=1; i<n; i++){
        sum =0;
        temp=i;
        sum+=i;
        while(temp){
            sum+=temp%10;
            temp/=10;
        }
        if(sum==n)
            break;
    }
    //출력
    if(sum!=n) cout<<'0'<<'\n';
    else cout<<i<<'\n';
}
