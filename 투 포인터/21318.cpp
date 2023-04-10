#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<int>v(n+1,0);
    vector<int>miss(n+1,0);

    for(int i=1; i<=n; i++){
        cin>>v[i];
        miss[i] = miss[i-1];
        if(v[i]<v[i-1]) miss[i]++;
    }

    int q,s,e; cin>>q;
    while(q--){
        cin>>s>>e;
        cout<<miss[e] - miss[s]<<'\n';
    }
}
