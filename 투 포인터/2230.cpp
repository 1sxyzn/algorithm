#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int p1=0, p2=0;
    int ans=2000000001;
    while(p1<n && p2<n){
        if(p1>p2) {
            p2++;
            continue;
        }
        if(v[p2]-v[p1] >= m){
            ans = min(ans, v[p2]-v[p1]);
            p1++;
        }
        else p2++;
    }
    cout<<ans;
}
