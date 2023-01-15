#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m,k;
    cin>>n>>m;
    vector<int>sum(n+1,0);
    for(int i=1; i<=n; i++){
        cin>>k;
        sum[i]=sum[i-1]+k;
    }
    int a,b;
    while(m--){
        cin>>a>>b;
        cout<<sum[b]-sum[a-1]<<'\n';
    }
}
