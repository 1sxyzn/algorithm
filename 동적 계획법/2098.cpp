#include<iostream>
#include<vector>

using namespace std;

int INF = 1000000 * 16 + 1;
int n;
vector<vector<int>>cost;
vector<vector<int>>ans;

int TSP(int city, int bit){
    // n=4 일때, 도시 다 돌면 1111이 됨 = 1<<n -1 = 15
    if(bit == (1<<n) - 1) return cost[city][0]==0 ? INF : cost[city][0]; // 시작 도시로 못가면 inf, 아니면 값 return (삼항연산자)

    // 이미 방문했던거면 저장된 값 return
    if(ans[city][bit]!=0) return ans[city][bit];

    int minimum = INF;
    for(int i=0; i<n; i++){
        // 전에 방문 X + 방문 가능할 떄
        // (bit & (1<<i)) 의 경우, 현재 방문했던 리스트(비트)와 원하는 도시에만 1이 되어있는 비트를 and 연산
        // (bit | (1<<i)) 의 경우, 원하는 도시에 1이 체크되어있기 때문에 or 연산을 통해 bit에 저장 가능
        if((bit & (1<<i))==0 && cost[city][i]!=0) minimum = min(minimum, TSP(i, (bit|(1<<i))) + cost[city][i]);
    }
    return ans[city][bit]=minimum;
}

int main(){
    cin>>n;
    cost.assign(16, vector<int>(16,0));
    ans.assign(16, vector<int>(1<<16, 0)); // 비트마스킹,1<<16은 00...001 을 왼쪽으로 16번 shift

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin>>cost[i][j];
    }

    cout<<TSP(0,1); // 시작은 어디서 해도 상관 없지만 0번 도시부터 시작 (0번 도시만 방문 시 001, 1번 .. 010, 2번 .. 100)
}
