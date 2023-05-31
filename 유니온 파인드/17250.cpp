
#include<iostream>
#include<vector>

using namespace std;

vector<int>parent;
vector<int>cnt;

int find_parent(int a){
    if(parent[a]==a) return a;
    else{
        parent[a] = find_parent(parent[a]);
        return parent[a];
    }
}

void union_set(int a, int b){
    a= find_parent(a);
    b= find_parent(b);
    if(a!=b){
        parent[b]=a;
        cnt[a]+=cnt[b];
        cnt[b]=0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    parent.assign(n+1,0);
    cnt.assign(n+1,0);
    for(int i=1; i<=n; i++){
        parent[i]=i;
        cin>>cnt[i];
    }

    int a,b;
    while(m--){
        cin>>a>>b;
        union_set(a,b);
        cout<<cnt[find_parent(a)]<<'\n';
    }
}
