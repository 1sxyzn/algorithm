#include <iostream>
#include <vector>
#include <queue>

//1463 번에 역추적 추가!

using namespace std;
const int SIZE=1e6;

vector<int> back(int n, vector<int> path) {
    vector<int> result;
    int x=1;
    while(x!=n){
        result.push_back(x);
        x=path[x];
    }
    return result;
}

int bfs(int n, vector<int> &path){
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
                path[x/3]=x; // x/3은 x로 부터 왔다는 의미, 역추적시 사용
            }
            if (x % 2 == 0 && !check[x / 2]) {
                q.push(x / 2);
                check[x / 2] = 1;
                path[x/2]=x; // x/2은 x로 부터 왔다는 의미, 역추적시 사용
            }
            if (!check[x - 1]) {
                q.push(x - 1);
                check[x - 1] = 1;
                path[x-1]=x; //x-1은 x로 부터 왔다는 의미, 역추적시 사용
            }
        }
        cnt++;
    }
}

int main(){
    vector<int> path(SIZE+1,0);
    int n;
    cin>>n;

    //역추적
    cout<<bfs(n, path)<<'\n';

    vector<int> result = back(n, path);
    cout<<n<<' ';
    for (int i = result.size()-1; i >= 0; i--)
        cout << result[i] << ' ';
}
