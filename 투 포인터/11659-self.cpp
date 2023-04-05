#include<iostream>
#include<vector>

using namespace std;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    vector<int>v(n+1,0);
    for(int i=1; i<=n; i++){
        cin>>v[i];
        v[i] = v[i-1] + v[i];
    }

    int a,b;
    while(m--){
        cin>>a>>b;
        cout<<v[b]-v[a-1]<<'\n';
    }
}
