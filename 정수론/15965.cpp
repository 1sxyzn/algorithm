#include<iostream>
#include<vector>

using namespace std;

const int MAX = 7368787+1; // 500000번째 소수는 7368787

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
