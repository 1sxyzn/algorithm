#include<iostream>
#include<vector>
#include<queue>

using namespace std;
const int SIZE = 1e5;

//1697번. 숨바꼭질과 유사
//BFS에 역추적 추가

vector<int> back(int k, vector<int> &path){ //도착점인 k 부터 거슬러 올라가서 역추적
    vector<int> ans;
    while(k != -1){ //path -1이면 시작점이니 반복 중지
        ans.push_back(k);
        k=path[k]; //부모, 즉 이전 경로 찾아가며 역추적
    }
    return ans;
}

int bfs(int n, int k, vector<int> &path){
    vector<int>check(100001,0);
    queue<int>q;
    int time=0;

    check[n]=1;
    q.push(n);

    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(x==k) {
            time=check[x]-1;
            break;
        }
        vector<int>child={x-1, x+1, x*2};
        for(int i=0; i<3; i++){
            if(child[i]>= 0 && child[i]<= 100000 && check[child[i]]==0){
                check[child[i]] = check[x] + 1;
                path[child[i]] = x; //경로, 즉 i의 부모노드인 x 저장
                q.push(child[i]);
            }
        }
    }

    return time;
}

int main(){
    vector<int>path(SIZE+1,-1); //역추적할 때 필요한 배열, -1로 초기화
    int n,k;
    cin>>n>>k;

    //시간 출력
    cout<<bfs(n,k,path)<<'\n';

    //경로 출력
    vector<int> result = back(k, path);

    for(int i=result.size()-1; i>=0; i--){ //back 함수를 통해 경로의 반대로 배열에 담았으니 반대로 출력
        cout<<result[i]<<' ';
    }
}
