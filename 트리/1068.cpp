#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>tree;
vector<int>parent;
vector<bool>visit;
int d, answer=0;

void dfs(int node){
    visit[node]=true;
    int child=0;

    for(int i=0; i<tree[node].size(); i++){
        if(!visit[tree[node][i]] && tree[node][i]!=d){
            child++;
            dfs(tree[node][i]);
        }
    }
    if(child==0) answer++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    tree.assign(n,vector<int>(0));
    parent.assign(n,0);
    visit.assign(n,false);

    int p, root;
    for(int i=0; i<n; i++){
        cin>>p;
        if(p!=-1){
            tree[i].push_back(p);
            tree[p].push_back(i);
        }
        else root=i;
    }

    cin>>d;

    if(root==d) cout<<0;
    else{
        dfs(root);
        cout<<answer;
    }
}
