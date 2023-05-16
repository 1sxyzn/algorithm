#include<iostream>
#include<vector>

using namespace std;

vector<int>parent;
vector<int>cnt;

int find_parent(int node){
    if(node==parent[node]) return node;
    else {
        parent[node] = find_parent(parent[node]);
        return parent[node];
    }
}

void union_set(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a!=b) {
        parent[b] = a;
        cnt[a] += cnt[b]; // 부모 노드에 하위 노드 갯수 저장하기
        cnt[b] = 0; // 1-2, 1-3, 2-3 으로 연결이 됐을 때 cnt[b]=0으로 초기화하지 않으면 중복 합이 됨
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    cnt.assign(1000001,1);
    parent.assign(1000001,0);
    for(int i=0; i<=1000000; i++) parent[i]=i;

    while(n--){
        char c;
        cin>>c;
        if(c=='I'){
            int a,b;
            cin>>a>>b;
            union_set(a,b);
        }
        else{
            int a;
            cin>>a;
            cout<<cnt[find_parent(a)]<<'\n'; // 하위 노드 갯수 총합은 부모 노드에 저장되어있음
        }
    }
}
