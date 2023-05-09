//
// Created by USER on 2023-05-09.
//
#include<iostream>
#include<algorithm>

using namespace std;

bool isPrime(int p){
    for(int i=2; i*i<=p; i++){
        if(p%i==0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;
    cin>>a>>b;

    for(int i=a; i<=10000000; i++){ // 시간초과 방지, 소수 & 팰린드롬인 수 중 10000000 넘는 수가 없다고 함
        if(i>b) break;
        string s = to_string(i);
        reverse(s.begin(), s.end());
        if(i == stoi(s) && isPrime(i)){
            cout<<i<<'\n';
        }
    }
    cout<<-1;
}