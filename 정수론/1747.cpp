#include<iostream>
#include<vector>

using namespace std;

bool check(int n){
    string s= to_string(n);
    int start=0, end=s.length()-1;
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++; end--;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<bool>prime(2000001,true);
    prime[0]=prime[1]=false;
    for(int i=2; i*i<=2000000; i++){
        for(int j=i+i; j<=2000000; j+=i){
            prime[j]=false;
        }
    }
    while(true){
        if(prime[n] && check(n)){
            cout<<n;
            break;
        }
        n++;
    }
}
