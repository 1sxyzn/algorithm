#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, num;
    cin>>n;
    vector<int>v(n+1,0);
    for(int i=1; i<=n; i++){
        cin>>num;
        v[i]+=v[i-1]+num;
    }
    int m, a, b;
    cin>>m;
    while(m--){
        cin>>a>>b;
        cout<<v[b]-v[a-1]<<'\n';
    }
}
