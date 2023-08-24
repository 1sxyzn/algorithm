#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){ // 나무를 많이 자르는 것이 목표
    int n, m;
    cin>>n>>m;
    vector<int>wood(n,0);
    for(int i=0; i<n; i++){
        cin>>wood[i];
    }
    sort(wood.begin(), wood.end());
    int s = 0;
    int e = wood[n-1];
    long long ans = 0;
    while(s<=e){
        long long mid = (s+e)/2;
        long long sum = 0;
        for(int i=0; i<n; i++){
            if(wood[i]>=mid)
            sum += wood[i] - mid;
        }
        if(sum>=m){ // 나무를 더 자를 수 있음
            s = mid + 1;
            ans = max(ans, mid);
        }
        else if(sum<m){ // 나무를 더 잘라야 목표 나무량에 도달
            e = mid - 1;
        }
    }
    cout<<ans;
}
