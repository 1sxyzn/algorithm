#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE=1e6;

int bfs(int n){
    vector<int> check(SIZE+1,0);
    queue<int> q;
    int cnt=0;

    check[n]=1;
    q.push(n);

    while(!q.empty()){
        int q_size = q.size();
        while(q_size--) {
            int x = q.front();
            q.pop();
            if (x == 1) {
                return cnt;
            }
            if (x % 3 == 0 && !check[x / 3]) {
                q.push(x / 3);
                check[x / 3] = 1;
            }
            if (x % 2 == 0 && !check[x / 2]) { //else if 사용하면 세가지 조건 중 하나에 걸리면 나머지는 탐색안해버림, if문 쓰기
                q.push(x / 2);
                check[x / 2] = 1;
            }
            if (!check[x - 1]) {
                q.push(x - 1);
                check[x - 1] = 1;
            }
        }
        cnt++;
    }
}

int main(){
    int n;
    cin>>n;

    cout<<bfs(n)<<'\n';
}

