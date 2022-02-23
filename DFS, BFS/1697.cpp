#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int bfs(int n, int k){
    vector<int>check(100001,0); //방문 여부와 도달 시간 저장
    queue<int>q;
    int time=0;

    check[n]=1; // 첫노드 방문체크, 시간 초기화
    q.push(n);

    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(x==k) { //동생을 잡으면
            time=check[x]-1; //while 처음 반복한다고 생각해보자
            // 위에서 check[n]=1 로 초기화 했으니 check[x]-1 해주어야함.
            // check[n]=0 으로 초기화 했으면 time=check[x]; 라고 해도 되지 않는가?
            //안된다. 그 경우 아래 반복문에 걸려서 n까지 도달하는데 1초라고 카운트하는데
            //n은 시작 자리 이므로 카운트하면 안된다.
            break;
        }
        vector<int>child={x-1, x+1, x*2}; //이동할 수 있는 좌표를 bfs 탐색
        for(int i=0; i<3; i++){
            if(child[i]>= 0 && child[i]<= 100000 && check[child[i]]==0){
                check[child[i]] = check[x] + 1;
                q.push(child[i]);
            }
        }
    }

    return time;
}

int main(){
    int n,k;
    cin>>n>>k;

    cout<<bfs(n,k)<<'\n';
}
