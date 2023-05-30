#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>parent;
vector<pair<int,int>>cnt;

int find_parent(int a){
    if(parent[a]==a) return a;
    else{
        parent[a] = find_parent(parent[a]);
        return parent[a];
    }
}

void union_set(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a!=b){
        parent[b]=a;
        cnt[a].first+=cnt[b].first;
        cnt[b].first=0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    parent.assign(n+1,0);
    cnt.assign(n+1, {1,0});
    for(int i=1; i<=n; i++) {
        parent[i]=i;
        cnt[i].second=i;
    }

    int a,b;
    while(m--){
        cin>>a>>b;
        union_set(a,b);
    }

    int c,h,k;
    cin>>c>>h>>k;
    int ans = cnt[c].first;
    sort(cnt.begin(), cnt.end(), greater<>());
    for(int i=0; i<n; i++){
        if(cnt[i].second != c && cnt[i].second != h && k>0){
            k--;
            ans+=cnt[i].first;
        }
    }
    cout<<ans;
}
