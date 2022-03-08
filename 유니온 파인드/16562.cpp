#include<iostream>
#include<vector>

using namespace std;
/*
 * weight union find
 * 우선 본인의 친구비에 마이너스를 붙여서 parent 배열에 저장한다
 * 그리고 관계를 파악해서 트리를 그려나간다. 친구비가 적은 애가 루트이다.
 * 생성된 트리의 자식 노드라면, parent 배열에 부모 노드의 인덱스를 넣는다.
 */

vector<int> parent;

//부모 노드 찾기
int findParent(int x){
    if(parent[x]<0) //부모 노드라면
        return x; //해당 노드의 리턴
    //그래프 압축하며 부모 찾기
    return parent[x]= findParent(parent[x]);
}

//a와 b는 친구이므로 같은 집합으로 union 해준다
void unionFriend(int a, int b){
    int a_parent= findParent(a);
    int b_parent= findParent(b);

    if(a_parent==b_parent) //같은 집합에 있으면 유니온 x
        return;
    //친구비는 누적되는게 아니라 한 친구의 친구비만 적용되는 것이므로 친구 수 셀 필요 x
    //친구비는 parent에 음수로 저장. 따라서 친구비가 더 적은 a를 부모로
    if(parent[a_parent]>parent[b_parent])
        parent[b_parent]=a_parent; //b의 부모를 a로 지정
    else
        parent[a_parent]=b_parent;
}

//모든 친구를 사귀는데의 최소한의 비용 구하기
int friendCost(int n){
    int sum=0;
    for(int i=1; i<=n; i++){
        if(parent[i]<0)
            sum+=parent[i];// 트리의 부모 노드들의 친구비만 더하기
    }
    return -sum; //친구비는 음수로 저장되어있으므로 부호 변경
}

int main(){
    int n,m,k,v,w,cost;
    cin>>n>>m>>k;
    parent.assign(n+1,0);
    for(int i=1; i<=n; i++){
        cin>>cost;
        parent[i]=-cost; //친구비를 음수로 저장
    }

    //친구간의 관계 저장
    while(m--){
        cin>>v>>w; //v와 w는 친구
        unionFriend(v,w);
    }

    int ans = friendCost(n);

    if(ans<=k) //가진 돈보다 친구비가 적다면 친구 가능
        cout<<ans;
    else
        cout<<"Oh no";
    cout<<'\n';
}
