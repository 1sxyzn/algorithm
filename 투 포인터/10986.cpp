#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    long long k, ans=0;
    cin>>n>>m;
    vector<long long>sum(n+1,0); // 누적합 저장할 배열
    vector<long long>cnt(m,0); // cnt[i] => (누적합 배열에서) 나머지가 i인 원소 갯수
    for(int i=1; i<=n; i++){
        cin>>k;
        sum[i]+=sum[i-1]+k;
        sum[i]%=m;
        cnt[sum[i]]++;
        if(sum[i]==0) ans++; // 처음부터 해당 구간까지 더한 누적합이 m 으로 떨어짐
    }
    for(int i=0; i<m; i++){
        if(cnt[i]>1) ans+=(cnt[i]*(cnt[i]-1))/2; // 조합 nC2
    }
    cout<<ans;
}
