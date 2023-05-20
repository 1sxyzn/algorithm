#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<bool>prime(1000000,true);
    prime[0] = prime[1] = false;
    for(int i=2; i*i<1000000; i++){
        for(int j=i+i; j<1000000; j+=i){
            prime[j]=false;
        }
    }

    int bef_prime=2;
    for(int i=3; i<1000000; i++){
        if(prime[i]){
            if(bef_prime * i > n){
                cout<<bef_prime * i;
                break;
            }
            bef_prime = i;
        }
    }
}
