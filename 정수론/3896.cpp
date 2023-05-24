#include<iostream>
#include<vector>

using namespace std;

const int MAX = 1299709+1;

int main(){
    int t;
    cin>>t;
    vector<bool> prime(MAX,true);
    prime[0]=prime[1]=false;
    for(int i=2; i*i<=MAX; i++){
        for(int j=i+i; j<=MAX; j+=i){
            prime[j]=false;
        }
    }

    while(t--){
        int p, pmn=0, ppn=0, ans=0;
        cin>>p;
        if(prime[p]) {
            cout<<0<<'\n';
            continue;
        }
        for(int i=p-1; i>=2; i--){
            if(prime[i]){
                pmn=i;
                break;
            }
        }
        for(int i=p+1; i<=MAX; i++){
            if(prime[i]) {
                ppn=i;
                break;
            }
        }
        for(int i=pmn+1; i<=ppn; i++){
            if(!prime[i]){
                ans++;
            }
        }
        if(ans!=0) cout<<ans+1<<'\n';
        else cout<<0<<'\n';
    }
}
