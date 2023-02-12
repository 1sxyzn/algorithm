#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<int>v(n,0);

    int start=0, end=0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(v[i]>start) start=v[i];
        end+=v[i];
    }
    while(start<=end){
        // 현 블루레이 크기에 다 담기면 크기 줄이고, 다 안 담기면 크기 늘리기
        int mid = (start+end)/2;
        int sum = 0; // 현재 블루레이에 담긴 강의 길이
        int cnt = 1; // 블루레이 갯수

        for(int i=0; i<n; i++){
            if(sum + v[i] > mid){ // 블루레이 넘침
                cnt++;
                sum=0; // 블루레이 리셋
            }
            sum+=v[i];
        }
        if(cnt>m) start=mid+1;
        else end=mid-1;
    }
    cout<<start;
}
