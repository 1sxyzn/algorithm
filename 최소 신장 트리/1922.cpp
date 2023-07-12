#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

vector<int>parent;

int find_parent(int node){
    if(node == parent[node]) return node;
    else return parent[node] = find_parent(parent[node]);
}

void union_set(int a, int b){
    a = find_parent(a);
    b = find_parent(b);

    if(a!=b) parent[b]=a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>>pq; // 간선은 오름차순,, ~
    parent.assign(n+1,0);
    for(int i=0; i<=n; i++) parent[i]=i;

    while(m--){
        int s,e,w;
        cin>>s>>e>>w;
        pq.push({w,s,e});
    }

    int ans=0;
    int edge=0;

    while(edge < n-1){ // 모든 노드가 연결되려면 n-1개의 간선 필요
        int w = get<0>(pq.top());
        int s = get<1>(pq.top());
        int e = get<2>(pq.top());
        pq.pop();

        if(find_parent(s) != find_parent(e)){
            union_set(s,e);
            ans += w;
            edge++;
        }
    }

    cout<<ans;
}
