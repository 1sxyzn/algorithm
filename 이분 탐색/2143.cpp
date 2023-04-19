#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;

    int n;
    cin>>n;
    vector<int>a(n,0);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<long long>sumA;
    // 누적 합 구하기
    for(int i=0; i<n; i++){
        long long sum=0;
        for(int j=i; j<n; j++){
            sum += a[j];
            sumA.push_back(sum);
        }
    }

    int m;
    cin>>m;
    vector<int>b(m,0);
    for(int i=0; i<m; i++) cin>>b[i];
    vector<long long>sumB;
    // 누적 합 구하기
    for(int i=0; i<m; i++){
        long long sum=0;
        for(int j=i; j<m; j++){
            sum += b[j];
            sumB.push_back(sum);
        }
    }

    long long ans=0;
    //이분 탐색
    sort(sumA.begin(), sumA.end());
    for(int i=0; i<sumB.size(); i++){
        long long find = t - sumB[i];
        auto up = upper_bound(sumA.begin(), sumA.end(), find); // find 초과하는 idx
        auto lo = lower_bound(sumA.begin(), sumA.end(), find); // find 이상인 첫 idx
        ans += (up - lo);
    }

    cout<<ans;
}
