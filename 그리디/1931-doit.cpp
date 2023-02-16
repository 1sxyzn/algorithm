#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int,int>a, pair<int,int>b){
    if(a.second!=b.second) return a.second<b.second;
    else return a.first<b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int,int>>v(n,{0,0});
    for(int i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(), v.end(), cmp);

    int end=0, ans=0;
    for(int i=0; i<n; i++){
        if(v[i].first>=end){
            ans+=1;
            end=v[i].second;
        }
    }
    cout<<ans;
}
