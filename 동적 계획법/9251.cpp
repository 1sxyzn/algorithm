#include<iostream>
#include<vector>

using namespace std;

/*
 * dp 값에는 최장 공통 부분 수열의 길이를 저장한다

 * LCS의 경우 이차원 표를 그리면 쉽게 알 수 있다.
 * 두 문자열에서 같은 수가 나오면 좌상향 대각선 수 + 1을 한다.
 * 예를 들어, BC라는 문자와 BK라는 문자열에 공통으로 A가 추가된다면
 * BCA, BKA가 되어야 한다. 이때, 공통 문자열은 BA가 된다.
 * 좌상향 대각선이 아니라 상 방향에서 dp 값을 가져왔다고 하면 A를 추가했을 때 BA, BKA 가 된다.
 * 좌 방향에서 dp 값을 가져오게 되면 A 추가 시 BCA, BA가 된다.
 * 즉 좌 방향, 상 방향에서 dp값을 가져오면 원하는 문자열을 만들 수 없게 된다. 그러므로 좌상향 대각선에서 dp 값을 가져온다
 * 표를 그리면 이해가 쉽다.

 * 다른 문자열이 나오면, 좌, 상 방향 중 최댓값을 그대로 가져온다.
 * 좌, 상 방향 중 최댓값이, 그 전의 공통 문자열의 최대 길이 이기 때문이다.
 */

int LCS(string a, string b){
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp (n+1, vector<int>(m+1, 0)); //dp 인덱스 1부터 사용 (i-1 접근하므로)
    for(int i=1; i<=n;i++){
        for(int j=1; j<=m; j++){ //dp 인덱스는 1부터 시작하지만 문자열 인덱스는 0부터 시작하므로 i-1로 접근
            if(a[i-1] == b[j-1]) // 같은 문자를 만나면 좌상향 대각선 값 + 1
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main(){
    string a,b;
    cin>>a>>b;

    cout<<LCS(a,b)<<'\n';

}
