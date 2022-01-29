#include<iostream>
#include<vector>

using namespace std;

int maxScore(int n, vector<int> score){
    vector<int>dp(n+1, 0);
    dp[1]=score[1]; //첫 번째 계단 점수 저장
    dp[2]=score[1]+score[2];//dp[i-2]를 접근해야 하므로 dp[2] 값 미리 저장
    // 두 번째 계단 오르는 경우는 첫 번째 계단을 밟고 한칸 올라가는 방법 밖에 없음

    //dp[i-3]을 접근하는데 dp[3]을 저장하지 않은 이유?
    //문제가 되는 경우는 i-3을 접근하는데 i=3 일 때, 우리가 사용하지 않을 dp[0]을 접근하는 경우이다.
    //하지만 dp[0]=0이고, dp[0]+score[2] = score[2] 가 된다.
    //즉 3번째 계단을 오를 때는 score[2] + score[3] 이 된다.
    //근데 이때 (score[2] = 1, 2 번째 계단을 오르는거고 score[3] = 3 번째 계단을 오르는 것이므로) 1, 2, 3 계단 연속 3번 밟게 되는게 아닌가?
    // -> 아니다. 연속 3개인지 카운트 할 때 첫 번째 계단은 포함하지 않는다고 명시됨

    for(int i=3; i<=n; i++){
        // (이번에 2칸을 오르거나, 전에 2칸 오른 상태 + 이번에 1칸 오르기) 한 것 중 최댓값 + 현재 점수
        //왜냐하면 dp[i-3] + score[i-1]를 하지 않으면 한칸씩 연달아 3번 오르게 될 수 있음
        //따라서 한칸을 오르려면 전전에 두칸 올라야만 [ 2칸 -> 1칸 -> 1칸 ] 이 되고, 연속 1칸씩 3번 오르지 않게 됨
        dp[i] = max(dp[i-2],dp[i-3] + score[i-1]) + score[i];
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    vector<int> score(n+1,0); //n+1인 이유? 인덱스 1부터 시작하기 위해서
    //인덱스 1부터 시작하는 이유? [i-1]를 접근해야하기 때문
    for (int i=1; i<=n; i++)
        cin>>score[i];

    cout<<maxScore(n, score)<<'\n';

}
