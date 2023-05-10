#include<iostream>
#include<vector>

using namespace std;

const int MAX = 104729+1; // 10000번째 소수는 104729

int main(){
    int n;
    cin>>n;
    vector<bool>prime(MAX,true);
    for(int i=2; i*i<=MAX; i++){
        for(int j=i+i; j<=MAX; j+=i){
            prime[j]=false;
        }
    }
    int cnt=0;
    for(int i=2; i<=MAX; i++){
        if(prime[i]){
            cnt++;
        }
        if(cnt==n){
            cout<<i;
            break;
        }
    }
}
