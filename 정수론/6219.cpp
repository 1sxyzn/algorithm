#include<iostream>
#include<vector>

using namespace std;

int main(){
    int a,b,d;
    cin>>a>>b>>d;
    vector<bool> prime(b+1,true);
    prime[0] = prime[1] = false;
    for(int i=2; i*i<=b; i++){
        for(int j=i+i; j<=b; j+=i){
            prime[j]=false;
        }
    }
    int ans=0;
    for(int i=a; i<=b; i++){
        if(prime[i]){
            int temp=i;
            while(temp){
                if(temp%10==d){
                    ans++;
                    break;
                }
                else temp/=10;
            }
        }
    }
    cout<<ans;
}
