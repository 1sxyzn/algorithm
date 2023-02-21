#include<iostream>

using namespace std;

long long gcd(long long a, long long b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main(){
    // 어마무시한 증명이 있지만.. A와 B의 최대 공약수는 len(A)와 len(B)의 최대공약수와 같다고 함 (단 모든 자리수가 1일때)
    long long a,b;
    cin>>a>>b;
    long long val=gcd(a,b);
    while(val--){
        cout<<1;
    }
}
