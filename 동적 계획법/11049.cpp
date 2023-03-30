#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int n;
static vector<pair<int,int>> mat;
static long long dp[501][501];

int calc(int start, int end){
    int result = INT_MAX;
    if(dp[start][end] != -1) return dp[start][end]; // 이미 계산했던 행렬
    if(start==end) return 0; // 자기 자신은 계산 횟수 0
    // dp 점화식
    for(int i=start; i<end; i++)
        result = min(result, mat[start].first * mat[i].second * mat[end].second + calc(start,i) + calc(i+1,end));
    return dp[start][end]=result;
}

int main(){
    cin>>n;
    mat.assign(n+1,{0,0});

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j]=-1;
        }
    }

    for(int i=1; i<=n; i++){
        int r, c;
        cin>>r>>c;
        mat[i]={r,c};
    }

    cout<<calc(1,n);
}
