#include <iostream>
using namespace std;
int main(){
    int n, m, left, right, ans=0;
    cin>>n;
    m=n;
    do{
        left=m/10;
        right=m%10;
        m=right*10 + (left + right) % 10;
        ans++;
    } while(n!=m);
    cout<<ans<<'\n';
}
