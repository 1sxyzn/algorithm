#include<iostream>

using namespace std;

int fac(int n, int k){
    int ans=1;
    for(int i=n; i>=k; i--)
        ans*=i;
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout<<fac(n,n-k+1)/fac(k,1)<<'\n';

}
