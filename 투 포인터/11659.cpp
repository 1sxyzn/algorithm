#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, num;
    cin>>n>>m;
    vector<int> sum(n+1,0);
    
    for(int i=1; i<=n; i++){//i-1 인덱스를 접근해야하니 i=1부터 시작
        cin>>num;
        sum[i] = sum[i-1]+num; //sum 에 누적합 저장
    }
    int a, b;
    while(m--){
        cin>>a>>b;
        cout<<sum[b]-sum[a-1]<<'\n';
    }
}
