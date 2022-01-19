#include<iostream>

using namespace std;

//유클리드 호제법을 이용해 최대공약수 구하기
int prime(int n, int m){
    while(m){
        int t=n%m;
        n=m;
        m=t;
    }
    return n;
}

//최대공약수 구해서 나누기
int main(){
    string s;
    cin>>s;

    int idx=s.find(':');
    int n = stoi(s.substr(0,idx));
    int m = stoi(s.substr(idx+1,s.length()));

    cout<<n/prime(n,m)<<":"<<m/prime(n,m)<<'\n';
}
