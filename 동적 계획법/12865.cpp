#include<iostream>
#include<vector>

using namespace std;

/*
 * 동적 계획법을 이용한 냅색 문제
 * dp의 인덱스를 무게로 나타내자!

 * 배낭에 넣을 수 있는 최대 무게가 7Kg 이라고 하자.
 * 그리고 넣을 물건 3kg 짜리가 있다고 하자.
 * 이 물건을 넣을 수도, 안 넣을 수도 있다.
 * 넣는다고 했을 때, 7-3 = 4kg 이므로,
 * 4kg인 배낭의 dp값 (4kg에 담을 수 있는 최대 가치 값) + 현재 3kg짜리 물건의 가치값
 * ... 을 계산해주자. 그리고 이 가치값과, 넣지 않았을 떄의 가치값을 비교해보자.
 * 그러다 보면 해당 무게 (7kg) 에서의 최대 가치 값을 구할 수 있다.
 */

struct info{ //명시적으로 파악하기 위해 구조체 사용, pair도 가능
    int w, v; //물건의 무게와 가치
};

int knapsack(int n, int k, vector<info> product){ //dp, 냅색
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

    for(int i=1; i<=n; i++){ //물품의 갯수 만큼
        for(int j=1; j < product[i].w; j++) // j < 넣어야 할 물건 무게 => 못 넣음 (1kg배낭에 3kg 넣을 수 없는 노릇)
            dp[i][j] = dp[i-1][j]; // 이전에 넣은 물건 (i-1) 에 대해, 현재 무게 (j) 에서의 최대 가치값 저장 => 이번 물건 안 넣는다는 이야기
        for(int j=product[i].w; j<=k; j++) // 넣어야 할 물건 무게 < 최대 버틸 수 있는 무게 => 물건 넣자!!
            //ex ) 4, 5, 6, 7 kg 배낭에 3kg 물건 넣을 수 있음.
            //이때 4kg 짜리 물건 하나 넣는 것 보다 3kg 물건 짜리 하나 넣는게 가치가 크다면
            //dp[4] 값을 3kg 물건의 가치 값으로 변경.. 이런 방식으로 dp 값 갱신!!

            // 1, 2 중 max 값을 구하자
            // 1. 이번 물건을 넣는 경우 = '이번 물품을 넣지 않았을 때의 무게 (= 최대 버틸 수 있는 무게 - 이번 물품의 무게를 뺀 값)' 에서의 최대 가치값 + 이번 물품의 가치값
            //  무슨 소리냐면, 7kg 배낭에 3kg 넣으려고 하는거라면, 7-3 = 4kg 이니까, 4kg 에서의 최대 가치값 + 3 kg 물품의 가치값
            //      == 4 + 3 = 7 kg을 담는 것이고, 3kg 물품의 가치값을 포함한 최대 가치값이 되는 것!!
            // 2. 이번 물건을 넣지 않는 경우 = 이번 물품을 넣지 않은 이전 물품의 j kg에서의 가치값
            dp[i][j] = max(dp[i-1][j-product[i].w] + product[i].v, dp[i-1][j]);
    }
    return dp[n][k]; //n개의 물건을 k kg 넣었을 때의 최대 가치값
}

int main() {
    int n, k; //물품의 수, 최대 버틸 수 있는 무게
    cin>>n>>k;

    vector<info> product(n+1, {0,0}); // n+1 개의 w와 v 모두 0으로 초기화
    for(int i=1; i<=n; i++)
        cin>>product[i].w>>product[i].v;

    cout<<knapsack(n, k, product)<<'\n';
}
