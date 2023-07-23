#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int>parent;
vector<int>cnt;

int find_parent(int node){
    if(parent[node]==node) return node;
    parent[node]= find_parent(parent[node]);
    return parent[node];
}

void union_set(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a!=b) {
        parent[b]=a;
        cnt[a]+=cnt[b];
        cnt[b]=0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<string,int> name;
        parent.assign(200001 ,0); // 100000 개의 관계가 들어올 수 있는데 모두 다른 사람이면 최대 200000명이 있음
        cnt.assign(200001,1);
        string s1, s2;
        int idx = 1;
        while(n--){
            cin>>s1>>s2;
            if(name[s1]==0) {
                name[s1] = idx;
                parent[idx] = idx;
                idx++;
            }
            if(name[s2]==0){
                name[s2] = idx;
                parent[idx] = idx;
                idx++;
            }
            union_set(name[s1], name[s2]);
            cout<<cnt[find_parent(name[s1])]<<'\n';
        }
    }
}
