#include<iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

/*
 * 가치가 1 3인 동전이 있다고 하자
 * 1~6 까지의 가치합을 만든다고 하면
 * 가치 1인 동전을 쓰면 동전의 갯수가 1 2 3 4 5 6 일 것이다.
 * 가치 3인 동전을 쓰면 동전의 갯수는 0 0 1 2 3 1 일 것이다.
 * 가치 1, 3 모두 쓰면 동전의 갯수는 1 2 1 2 3 1 일 것이다.
 * 이는 어떻게 구한 것 이냐면 가치 4를 만든다고 가정했을 때,
 * dp [현재가치 4 - 동전가치 3] = dp[1] = 1 에 +1 을 한 것이다~
 * 1 3 원 동전을 이용해 가치 7을 만든다고 해보자
 * dp [현재가지 7 - 동전가치 3] = dp[4] + 1 = dp[현재가치 4 - 동전가치 3] + 1 = dp[1] + 1 + 1 = 3
 * 이렇게 된 것이다.
 */

int minCoin(int n, int k, vector<int> value){
    vector<int>dp(k+1,INF);
    dp[0]=0;
    //dp[가치]=동전 갯수

    for(int i=0; i<n; i++){
        for(int j=value[i]; j<=k; j++){
            if(dp[j-value[i]] != INF) //현재 동전을 추가해서 새로 가치합을 갱신할 수 있을 때
                //j를 만들기 위해 이전에 계산한 동전 갯수와, 새 가치의 동전을 이용해 계산한 최종 동전 갯수 중 더 작은 동전 갯수를 이용
                dp[j]=min(dp[j], dp[j-value[i]]+1);
        }
    }

    if(dp[k]==INF)
        return -1;
    return dp[k];
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>value(n,0);
    for(int i=0; i<n; i++)
        cin>>value[i];
    cout<<minCoin(n, k, value)<<'\n';
}
