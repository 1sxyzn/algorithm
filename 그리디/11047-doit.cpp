#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, ans=0;
    cin>>n>>k;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    for(int i=n-1; i>=0; i--){
        if(k>=v[i]){
            ans+=(k/v[i]);
            k%=v[i];
        }
    }
    cout<<ans;
}
