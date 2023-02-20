#include<iostream>

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main(){
    int t,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cout<<a*b/gcd(a,b)<<'\n';
    }
}
