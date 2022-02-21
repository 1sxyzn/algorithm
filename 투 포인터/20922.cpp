#include<iostream>
#include<vector>

using namespace std;
const int MAX = 100000;

int maxStr(int n, int k, vector<int> arr){
    vector<int>count(MAX+1,0); //수의 빈도를 저장할 배열, 3이 4번 나오면 count[3] = 4
    int ans=0, left=0, right=0;

    while(left<=right && right<n) {
        if(count[arr[right]] + 1 <= k){ // while 돌면서 right를 이동시켰는데, right가 가리키는 수의 빈도가 k보다 작으면 수 추가 가능
            count[arr[right]]++; // 수 추가
            ans = max (ans, (right-left+1));
            right++; //right 이동
        }
        else { //빈도가 k 이하여야 하는데 k 보다 클 경우
            count[arr[left]]--;
            left++;
        }
    }
    return ans;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int>arr(n,0);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<maxStr(n, k, arr)<<'\n';
}
