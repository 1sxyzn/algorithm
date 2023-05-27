#include<iostream>
#include<vector>

using namespace std;

vector<int>parent;

int find_parent(int a){
    if(parent[a]==a) return a;
    else {
        parent[a]=find_parent(parent[a]); // 재귀 통해 제일 최상단의 부모 노드 찾기
        return parent[a];
    }
}

void union_set(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if(a!=b) parent[b]=a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        int n, a, b;
        cin>>n;
        parent.assign(n+1,0);
        for(int j=1; j<=n; j++) parent[j]=j;

        int k;
        cin>>k;
        while(k--){
            cin>>a>>b;
            union_set(a,b);
        }

        cout<<"Scenario "<<i<<":\n";

        int m;
        cin>>m;
        while(m--){
            cin>>a>>b;
            if(find_parent(a) == find_parent(b)) cout<<"1\n";
            else cout<<"0\n";
        }
        cout<<'\n';
    }
}
