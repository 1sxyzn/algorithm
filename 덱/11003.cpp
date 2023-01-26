#include<iostream>
#include<deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,l;
    cin>>n>>l;
    deque<pair<int,int>>dq; // 인덱스, 값 저장

    int a;
    for(int i=0; i<n; i++){
        cin>>a;
        while(!dq.empty() && dq.back().second>=a){ // 새로 입력 받은 값보다 큰 값 있으면 삭제
            dq.pop_back();
        }
        dq.emplace_back(i,a); // 새로 입력 받은 값 저장
        if(dq.front().first < i-l+1){ // 앞 부분에 인덱스 범위 포함 안되는 것들은 삭제
            dq.pop_front();
        }
        cout<<dq.front().second<<' ';
    }
}
