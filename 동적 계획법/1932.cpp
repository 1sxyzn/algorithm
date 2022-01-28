#include<iostream>
#include<vector>

using namespace std;

const int SIZE = 500;

// Bottom up
int main() {
    int triangle[SIZE+1][SIZE+1];
    int dp[SIZE+1][SIZE+1];

    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++)
            cin>>triangle[i][j];
    }

    dp[1][1]=triangle[1][1];
    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i][j]=max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            //삼각형의 왼쪽 대각선 위, 오른쪽 대각선 위 중 더 큰 값 + 현재 값.. 하면서 삼각형의 아래로 내려가기
        }
    }

    //최댓값 구하기
    int max = -1;
    for(int i = 1; i<=n; i++){ //마지막 줄(=값들의 합을 모아둠)에서의 최댓값 구하기
        if(max<dp[n][i])
            max=dp[n][i];
    }
    cout<<max<<'\n';
}
