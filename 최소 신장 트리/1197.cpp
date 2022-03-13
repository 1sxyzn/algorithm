#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
typedef tuple<int,int,int>tp;
vector<int>parent;

int findParent(int x){
    if(parent[x]<0) //루트 노드라면
        return x; //루트 값 리턴
    //그래프 압축하면서 루트 찾기
    return parent[x]= findParent(parent[x]);
}

//사이클이 생겼는지 여부를 파악하기 위해 bool 형으로
bool unionNode(int a, int b){
    int a_p = findParent(a); //a_p = a의 parent, 즉 a의 루트 값 저장
    int b_p = findParent(b);

    if(a_p==b_p) //부모가 같다면 유니온시 사이클 생성됨
        return false; //사이클 생기므로 유니온 X
    if (parent[a_p]<parent[b_p]) {//a의 자식 수가 더 많으므로 a_p를 새로운 루트로 (parent에는 음수로 자식 수 저장되어있음)
        parent[a_p] += parent[b_p];
        parent[b_p]=a_p;
    }
    else{
        parent[b_p]+=parent[a_p];
        parent[a_p]=b_p;
    }
    return true; //성공적으로 유니온하면 true 리턴
}

int kruskal(int v, priority_queue<tp, vector<tp>, greater<>>&pq){
    int cnt=0; //간선 갯수 저장
    int sum=0; //가중치 합 저장

    //사이클이 생기지 않는 트리를 만들려면 정점이 v개 일 때, 간선의 수가 v-1개 필요하다
    while(cnt<v-1){
        int weight = get<0>(pq.top()); //큐의 튜플의 첫번째에 저장된 가중치 값
        int x = get<1>(pq.top()); // 큐의 튜플의 두번째에 저장된 정점 x
        int y = get<2>(pq.top()); // 큐의 튜플의 세번째에 저장된 정점 y
        //x 정점과 y 정점으로 연결된 간선의 가중치가 weight이다.
        pq.pop();

        if(unionNode(x,y)){ //유니온이 가능하다면
            cnt++; //간선 갯수 추가
            sum+=weight; //가중치 누적 합하기
        }
    }
    return sum;
}

int main(){
    int v,e,a,b,c;
    cin>>v>>e;
    priority_queue<tp, vector<tp>, greater<>> pq; //가중치 작은 것 부터 저장
    parent.assign(v+1,-1);

    while(e--){
        cin>>a>>b>>c;
        pq.push({c,a,b}); //가중치 c를 기준으로 정렬하므로 c부터 저장
    }
    cout<<kruskal(v,pq);
}
