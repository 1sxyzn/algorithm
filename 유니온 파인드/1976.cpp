#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//x라는 도시의 부모 찾기. 부모가 같은 도시끼리는 방문이 가능한 것
int findParent(int x){
    if(parent[x]<0) //배열에 음수가 있으면 해당 x 가 부모임
        return x;
    //부모가 아닌 노드라면 그래프 압축해가며 부모 탐색
    return parent[x]= findParent(parent[x]);
}

//도시들을 합치기
void unionCountry(int a, int b){
    int ap= findParent(a); //ap는 a의 parent
    int bp= findParent(b); //bp는 b의 parent

    if(ap==bp) //부모가 같으면 같은 집합
        return;
    if(parent[ap]<parent[bp]) {//자식의 갯수는 음수로 저장. ap가 더 많은 자식 가지고 있으면 부모로 승격
        parent[ap] += parent[bp]; //bp의 자식 갯수까지 누적합 해줌
        parent[bp] = ap; //bp의 부모를 ap이므로 ap를 가리키게 설정
    }
    else{
        parent[bp]+=parent[ap];
        parent[ap]=bp;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    parent.assign(n+1,-1);
    int trip;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) {
            cin >> trip;
            if(trip) //1이 들어오면 도시 연결
                unionCountry(i,j);
        }
    }
    int a,b;
    cin>>a; //시작 도시
    while(--m){//시작 도시는 while 밖에서 따로 받았으므로 m-1번만 반복
        cin>>b;
        if(findParent(a)!=findParent(b)){ //부모가 다르면 연결이 안된 도시. 방문 불가
            cout<<"NO";
            return 0; //프로그램 종료
        }
    }
    cout<<"YES";
}
