#include<iostream>
using namespace std;
int main(){
    string a, b;
    cin>>a>>b;
    int c=0, d=0;
    for(int i=2; i>=0; i--){
        c*=10; d*=10;
        c+=int(a[i]-'0'); d+=int(b[i]-'0');
    }
    cout<<max(c,d);
}
