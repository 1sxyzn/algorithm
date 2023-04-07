#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q; cin>>n>>q;
    vector<int>a(n+1,0);
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());
    for(int i=1; i<=n; i++){
        a[i] += a[i-1];
    }

    int s,e;
    while(q--){
        cin>>s>>e;
        cout<<a[e] - a[s-1]<<'\n';
    }
}
