#include <iostream>
#include <deque>
#include <vector>

// 0-1 BFS문제
// 최단거리 문제이지만 가중치가 0,1일 때는 다익스트라 말고 0-1 BFS로 풀이할 수 있다.
// 덱 deque를 이용하고, 가중치가 0인걸 우선순위로 두기 때문에 앞에 넣으면 되고
// 가중치가 1인것은 우선순위가 낮기 때문에 뒤에 넣는다.

using namespace std;

const int SIZE = 100001;

int zeroOneBFS(int n, int k){
    vector<int> check(SIZE,0); //방문 확인 & 소요 시간 저장
    deque<int> dq;

    check[n]=1;
    dq.push_back(n);

    while(!dq.empty()){
        int x=dq.front();
        dq.pop_front();

        if(x==k)
            return check[x]-1;

        //순간이동
        if(x*2<SIZE && !check[x*2]){
            dq.push_front(x*2);
            check[x*2]=check[x];
        }

        //앞으로 걷기
        if(x+1<SIZE && !check[x+1]){
            dq.push_back(x+1);
            check[x+1]=check[x]+1; //1초 증가
        }

        //뒤로 걷기기
        if(x-1>=0 && !check[x-1]){
            dq.push_back(x-1);
            check[x-1]=check[x]+1; //1초 증가
        }
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<zeroOneBFS(n,k)<<'\n';
}
