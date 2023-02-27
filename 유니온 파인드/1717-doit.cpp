#include<iostream>
#include<vector>

using namespace std;

vector<int>parent; // 대표 노드 저장

int find_set(int a){ // 대표 노드 찾기
    if(a==parent[a]) return a;
    else {
        parent[a]=find_set(parent[a]);
        return parent[a];
    }
}

bool check_set(int a, int b){ // 같은 집합인지 확인
    a=find_set(a);
    b=find_set(b);

    if(a!=b) return false;
    else return true;
}

void union_set(int a, int b){ // 합치기
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        parent[b]=a;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    parent.assign(n+1,0);
    for(int i=1; i<=n; i++){
        parent[i]=i;
    }

    int cmd,a,b;
    while(m--){
        cin>>cmd>>a>>b;
        if(cmd==0){ // union
            union_set(a,b);
        }
        else{ // find
            if(check_set(a,b)) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
}
