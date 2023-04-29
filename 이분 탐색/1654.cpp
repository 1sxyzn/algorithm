#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k,n; // 가진 랜선 갯수 k, 필요한 랜선 갯수 n
    cin>>k>>n;
    vector<long long>cable(k,0);
    for(int i=0; i<k; i++){
        cin>>cable[i];
    }
    sort(cable.begin(), cable.end());

    long long ans = 0;
    long long start = 1;
    long long end = cable[k-1];
    long long mid;
    while(start<=end){ // start<end 로 하면 틀림
        mid = (start+end)/2;
        long long cnt = 0; // mid 길이로 잘랐을 때 나오는 랜선 갯수
        for(int i=0; i<k; i++){
            cnt += (cable[i]/mid);
        }

        if(cnt>=n){ // 원하는 랜선 갯수만큼 생성되면
            start = mid+1; // 더 길게 랜선을 자를 수 있는지 확인
            ans = max(mid, ans);
        }
        else end = mid-1; // 원하는 랜선 갯수가 안 나오면 랜선을 더 짧게 자르기
    }
    cout<<ans;
}
