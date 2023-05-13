#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<bool>prime(n+1,true);
        prime[0]=prime[1]=false;
        for(int i=2; i*i<=n; i++){
            for(int j=i+i; j<=n; j+=i){
                prime[j]=false;
            }
        }
        for(int i=n/2; i>=2; i--){
            if(prime[i] && prime[n-i]){
                cout<<i<<' '<<n-i<<'\n';
                break;
            }
        }
    }
}
