#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * 없애야 하는 전깃줄의 최소 개수를 구해야한다.
 * 전체 전갯줄의 갯수 - 연결이 "가장 길게 증가하는 갯수" = 없애야 하는 최소 전깃줄 로 풀 수 있다.
 * "가장 길게 증가하는 갯수"는 LIS 알고리즘과 같다.
 * LIS는 가장 긴 증가하는 부분수열 이다. LIS또한 dp를 이용하는 문제이다.
 */

int LIS(int n, vector<pair<int,int>> line){
    vector<int>dp(n,1);
    int longest = 1;

    for(int i=1;i<n;i++){
        for(int j=0; j<i; j++){
            if(line[i].second>line[j].second) //  = 증가하는 부분수열
                dp[i]=max(dp[i], dp[j]+1); // j 의 lis에 +1 하거나, i의 lis 그대로 쓰거나 (B[j]<B[i]인 상태)
        }
        longest=max(dp[i], longest); //lis가 더 긴게 있으면 갱신
    }
    return n-longest;
}

int main(){
    int n, a, b;
    cin>>n;
    vector<pair<int,int>> line(n);
    for(int i=0; i<n; i++)
        cin>>line[i].first>>line[i].second;
    sort(line.begin(), line.end());
    cout<<LIS(n, line)<<'\n';
}
