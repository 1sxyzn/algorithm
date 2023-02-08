#include<iostream>

using namespace std;

int n;
bool isPrime(int num){
    for(int i=2; i*i<=num; i++){
        if(num%i==0) return false;
    }
    return true;
}

void dfs(int num, int digit){
    if(digit==n) {
        if(isPrime(num)){
            cout<<num<<'\n';
            return;
        }
    }
    for(int i=1; i<=9; i+=2){
        if(isPrime(num*10+i)) dfs(num*10+i, digit+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    dfs(2,1);
    dfs(3,1);
    dfs(5,1);
    dfs(7,1);
}
