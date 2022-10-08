#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n<100) cout<<n;
    else {
        int ans = 99;
        for (int i = 100; i <= n; i++) {
            int k = i;
            int one = k % 10;
            k /= 10;
            if (k / 10 - k % 10 == k % 10 - one) ans++;
        }
        cout<<ans;
    }
}
