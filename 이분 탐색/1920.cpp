#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr.begin(), arr.end()); //이분 탐색은 정렬 필수

    int m, temp;
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>temp;
        cout<<binary_search(arr.begin(), arr.end(), temp)<<'\n';
    }
}
