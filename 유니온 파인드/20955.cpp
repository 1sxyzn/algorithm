#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> parent;

int find_parent(int node){
    if(node == parent[node]) return node;
    return parent[node] = find_parent(parent[node]);
}

void union_set(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    parent[b] = a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    parent.assign(n+1,0);
    for(int i=1; i<=n; i++) parent[i]=i;

    int a,b,ans=0;
    while(m--){
        cin>>a>>b;
        if(find_parent(a) != find_parent(b)) union_set(a,b); // 연결
        else ans++; // 사이클 있는 것이므로 연결 끊기
    }

    for(int i=1; i<=n; i++) if(i==parent[i]) ans++;
    cout<<ans-1<<'\n';
}
