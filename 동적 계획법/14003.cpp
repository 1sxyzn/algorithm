#include<iostream>
#include<vector>

using namespace std;

vector<int>arr;
vector<int>dp;
vector<int>cur; // 해당 값이 앞에서 몇번째로 증가하는 값인지 알기 위한 배열
vector<int>ans;
int n, max_len=1;

int binarySearch(int left, int right, int val){
    int mid;
    while(left<right){
        mid = (left+right)/2;
        if(cur[mid]<val) left=mid+1;
        else right=mid;
    }
    return right; // right나 left나 상관없음
}

int main(){
    cin>>n;
    arr.assign(n+1,0); dp.assign(n+1,0); cur.assign(n+1,0); ans.assign(n+1,0);
    for(int i=1; i<=n; i++) cin>>arr[i];

    cur[max_len] = arr[1];
    dp[1]=1;
    int idx;

    for(int i=2; i<=n; i++){
        if(cur[max_len] < arr[i]){ // 증가하는 값 찾으면
            max_len++;
            cur[max_len] = arr[i]; // cur 수열에, 값 저장
            dp[i] = max_len; // 최장 길이 저장
        }
        else{
            idx=binarySearch(1, max_len, arr[i]); // cur배열에서 해당 값보다 최초로 크거나 같아지는 idx 찾기
            cur[idx] = arr[i];
            dp[i] = idx;
        }
    }

    cout<<max_len<<'\n';
    int cur_max_len = max_len;
    int cur_max_val = cur[max_len] + 1; // 현 arr[i]의 다음으로 큰 값이 저장됨

    for(int i=n; i>=1; i--){
        if(dp[i]==cur_max_len && arr[i]<cur_max_val){
            ans[cur_max_len] = arr[i];
            cur_max_val = arr[i];
            cur_max_len--;
        }
    }

    for(int i=1; i<=max_len; i++){
        cout<<ans[i]<<' ';
    }
}
