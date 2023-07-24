#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>cost(n,vector<int>(3)); // 각각의 집을 각각의 색으로 칠하는 비용
    vector<vector<int>>calc(n,vector<int>(3,0)); // i 번쩨 집을 R,G,B 로 칠하는 비용 (누적)

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>cost[i][j];
        }
    }

    calc[0][0] = cost[0][0];
    calc[0][1] = cost[0][1];
    calc[0][2] = cost[0][2];

    for(int i=1; i<n; i++){
        calc[i][0] = min(calc[i-1][1], calc[i-1][2]) + cost[i][0];
        calc[i][1] = min(calc[i-1][0], calc[i-1][2]) + cost[i][1];
        calc[i][2] = min(calc[i-1][0], calc[i-1][1]) + cost[i][2];
    }

    cout<<min(calc[n-1][0], min(calc[n-1][1], calc[n-1][2]));
}
