#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    while(true){
        cin>>n;
        if(n==0) break;
        vector<bool> v(2*n+1,true);
        v[0]=false; v[1]=false;
        for(int i=2; i*i<=2*n; i++){
            for(int j=i+i; j<=2*n; j+=i)
                v[j]=false;
        }
        int ans=0;
        for(int i=n+1; i<=2*n; i++){
            if(v[i]) ans++;
        }
        cout<<ans<<'\n';
    }
}
