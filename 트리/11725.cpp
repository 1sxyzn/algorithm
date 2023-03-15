#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>tree;
vector<int>parent;
vector<bool>visit;

void dfs(int node){
    visit[node]=true;

    for(int i=0; i<tree[node].size(); i++){
        if(!visit[tree[node][i]]){
            parent[tree[node][i]]=node;
            dfs(tree[node][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;

    tree.assign(n+1, vector<int>(0));
    parent.assign(n+1,0);
    visit.assign(n+1, false);

    int p,c;
    for(int i=1; i<n; i++){
        cin>>p>>c;
        tree[p].push_back(c);
        tree[c].push_back(p);
    }

    dfs(1);

    for(int i=2; i<=n; i++){
        cout<<parent[i]<<'\n';
    }
}
