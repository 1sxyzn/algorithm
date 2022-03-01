#include <iostream>
#include <vector>

using namespace std;

pair<int,int> LIS(int n, vector<int> a, vector<int> &path){ //path 값은 변경되므로 & 필수!
    vector<int> dp(n,1);
    pair<int, int> ans = {1,0}; // 제일 긴 길이와, LIS에 해당되는 마지막 원소의 인덱스 저장

    for(int i=1; i<n; i++){
        int index=-1;
        for(int j=0; j<i; j++) {
            if(a[i]>a[j] && dp[i] < dp[j] + 1) { //증가하고 있고, j의 LIS가 더 길다면
                dp[i] = dp[j] + 1;
                index = j;
            }
        }
        path[i]=index; //i번째 원소의 LIS 값 갱신
        if(ans.first < dp[i]) //i번째 원소가 LIS라고 판명되면 갱신
            ans= {dp[i], i};
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> path(n,-1); //역추적할 경로
    for(int i=0; i<n; i++)
        cin>>a[i];

    pair<int, int> result = LIS(n, a, path);

    cout<<result.first<<'\n';

    vector<int>ans; //정답 인덱스을 역순으로 담을 것
    int x=result.second; //LIS에서 가장 큰 인덱스

    while (x != -1) {
        ans.push_back(x);
        x = path[x];
    }

    for(int i=ans.size()-1; i>=0; i--)
        cout<<a[ans[i]]<<' ';

}
