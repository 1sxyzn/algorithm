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

    int n;
    cin>>n;
    priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> pq;
    parent.assign(n+1,0);
    for(int i=0; i<=n; i++) parent[i]=i;

    int cost;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>cost;
            pq.push({cost,i,j});
        }
    }

    long long ans = 0;
    int edge = 0;
    while(edge < n-1){
        long long w = get<0>(pq.top());
        int s = get<1>(pq.top());
        int e = get<2>(pq.top());
        pq.pop();

        if(find_parent(s) != find_parent(e)){
            union_set(s,e);
            edge++;
            ans += w;
        }
    }
    cout<<ans;
}
