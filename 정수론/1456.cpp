#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a,b;
    cin>>a>>b;
    vector<bool>prime(10000001,true);
    prime[0]=prime[1]=false;
    for(int i=2; i*i<10000001; i++){
        for(int j=i+i; j<10000001; j+=i){
            prime[j]=false;
        }
    }
    int ans=0;
    for(int i=2; i<10000001; i++){
        if(prime[i]) {
            long long temp=i;
            while(i<=(double)b/(double)temp) {
                if((double)a/(double)temp<=i) ans++;
                temp *= i;
            }
        }
    }
    cout<<ans;
}
