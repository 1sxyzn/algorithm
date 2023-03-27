#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n,0);
    vector<int>l(n,0);
    vector<int>r(n,0);

    for(int i=0; i<n; i++) cin>>v[i];

    // 왼쪽 구간 합에서 최대
    l[0]=v[0];
    int sum=v[0]; // 별도로, 하나 제거 하지 않은 상태의, 최대 구간 합을 저장해두자
    for(int i=1; i<n; i++){
        l[i]= max(v[i], l[i-1]+v[i]);

        // 별도로, 하나 제거 하지 않은 상태의, 최대 구간 합을 저장해두자
        sum = max(sum, l[i]);
    }

    // 오른쪽 구간 합에서 최대
    r[n-1]=v[n-1];
    for(int i=n-2; i>=0; i--){
        r[i]= max(v[i], r[i+1]+v[i]);
    }

    // i를 제거했을 때 최대 값이 된다면 그 i 찾기
    for(int i=1; i<n-1; i++){
        int sum_except_one = l[i-1] + r[i+1];
        sum = max(sum ,sum_except_one);
    }

    cout<<sum;
}
