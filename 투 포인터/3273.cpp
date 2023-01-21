#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,x;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    cin>>x;
    int p1=0, p2=n-1;
    int ans=0;
    while(p1<p2){
        if(v[p1]+v[p2]==x){
            ans++;
            p1++; p2--;
        }
        else if(v[p1]+v[p2]<x){
            p1++;
        }
        else p2--;
    }
    cout<<ans;
}
