#include<iostream>

using namespace std;

int main(){
    int n,l,r;
    cin>>n>>l>>r;
    static long long bd[101][101][101];
    bd[1][1][1]=1;

    for(int i=2; i<=n; i++){
        for(int j=1; j<=l; j++){
            for(int k=1; k<=r; k++){
                // 젤 작은걸 가장 왼쪽에 배치, 오른쪽에 배치, 중간에 배치할 경우*(n-2개의 경우의 수)
                bd[i][j][k] = (bd[i-1][j-1][k] + bd[i-1][j][k-1] + bd[i-1][j][k]*(i-2)) % 1000000007;
            }
        }
    }

    cout<<bd[n][l][r];
}
