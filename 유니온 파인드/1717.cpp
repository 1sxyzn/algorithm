#include<iostream>
#include<vector>

using namespace std;
/*
 * weight union find
 * 우선 parent 벡터를 -1로 초기화
 * 해당 노드의 부모(root)가 있으면, parent에 부모 노드의 인덱스 값 넣기
 * 해당 노드가 부모라면 자식 노드의 갯수를 음수로 넣기, 자식 노드 3개면 -3 넣기
 */
vector<int> parent;

//find (같은 집합인지 확인)
int findParent(int a){
    //부모 노드이면 자식 노드의 갯수가 음수로 들어가 있음
    if(parent[a]<0)
        return a;
    //부모 노드가 아니라면 그래프를 압축해나가며 부모 노드 찾기
    return parent[a] = findParent(parent[a]);
}

//유니온 (집합 합치기)
void unionSet(int a, int b){
    int a_parent = findParent(a);
    int b_parent = findParent(b);

    if(a_parent==b_parent) // 이미 같은 집합이면 유니온 못함
        return;
    //자식 갯수가 많은게 새로운 부모가 됨
    //자식 갯수는 음수로 저장되어있으므로 부등호 유의
    if(parent[a_parent]<parent[b_parent]){
        parent[a_parent]+=parent[b_parent]; //자식 갯수 합해서 더해주기
        parent[b_parent]=a_parent; //자식 갯수 더 작은 b의 부모는 a가 됨
    }
    else{
        parent[b_parent]=parent[a_parent];
        parent[a_parent]=b_parent;
    }
}


int main(){
    //입출력 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; // n+1개의 집합, m번의 연산
    int cmd, a, b;
    cin>>n>>m;
    parent.assign(n+1,-1);
    while(m--){
        cin>>cmd>>a>>b;

        //유니온 (집합 합치기)
        if(cmd==0)
            unionSet(a,b);

        //find (같은 집합인지 확인)
        if(cmd==1){
            if(findParent(a)==findParent(b))
                cout<<"YES";
            else
                cout<<"NO";
            cout<<'\n';
        }
    }
}
