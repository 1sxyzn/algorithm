#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
    static long long dp[100001][5][5];
    int m[5][5] = { // m[i][j] = i칸에서 j칸으로 이동했을 때 힘의 크기
            {0,2,2,2,2},
            {2,1,3,4,3},
            {2,3,1,3,4},
            {2,4,3,1,3},
            {2,3,4,3,1}
    };

    for(int i=0; i<100001; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                dp[i][j][k] = 100001*4; // 가장 큰 수로 초기화
            }
        }
    }

    dp[0][0][0]=0;

    int goal, total=0;
    while(true){
        cin>>goal;
        if(goal==0) break;

        total++;
        for(int i=0; i<5; i++){ // i : 왼, j : 오
            if(goal==i) continue; // 두 발 같은 칸에 있는 경우
            for(int j=0; j<5; j++) dp[total][i][goal] = min(dp[total-1][i][j] + m[j][goal], dp[total][i][goal]); // 오른발 이동
        }

        for(int i=0; i<5; i++){ // i : 오, j : 왼
            if(goal==i) continue; // 두 발 같은 칸에 있는 경우
            for(int j=0; j<5; j++) dp[total][goal][i] = min(dp[total-1][j][i] + m[j][goal], dp[total][goal][i]); // 왼발 이동
        }
    }

    long long ans = LONG_LONG_MAX;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            ans = min(ans, dp[total][i][j]);
        }
    }
    cout<<ans;
}
