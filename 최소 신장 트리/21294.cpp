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
    parent.assign(n+1,0);
    for(int i=0; i<=n; i++) parent[i]=i;
    priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> pq;

    int s,e,w;
    long long sum=0;
    while(m--){
        cin>>s>>e>>w;
        pq.push({w,s,e});
        sum+=w;
    }

    long long ans=0, edge=0;
    while(!pq.empty()){
        int weight = get<0>(pq.top());
        int start = get<1>(pq.top());
        int end = get<2>(pq.top());
        pq.pop();

        if(find_parent(start) != find_parent(end)){
            union_set(start,end);
            ans += weight;
            edge++;
        }
    }

    if(edge == n-1) cout<<sum-ans;
    else cout<<-1;
}
