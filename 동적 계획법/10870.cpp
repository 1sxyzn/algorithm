#include<iostream>
#include<vector>

using namespace std;

/*
 * 재귀함수를 호출하다 보면 중복된 값을 호출하기도 함 -> 시간낭비
 * DP를 이용해서 값들을 저장해두고 중복된 값이 나오면 값을 바로 불러올 수 있게 하자
 * Top-down 방식 보다 Bottom-up 방식이 더 빠름
 */

const int SIZE = 20;

//DP, Top down 방식
int f(int n){
    vector<int> dp(SIZE + 1,0);
    if(n<=0)
        return 0;
    if(n==1)
        return 1;
    if(dp[n]) //이미 있는 값이면
        return dp[n];
    return dp[n] = f(n-1) + f(n-2);


}

int main(){
    int n;
    cin>>n;
    cout<<f(n)<<'\n';
}
