#include<iostream>
#include<utility>
#include<vector>

using namespace std;

int ans=0;

//n:일 하는 날, v: 시간과 수당이 담긴 벡터, start: 일 시작하는 날, sum: 수당의 합
void count(int n, vector<pair<int, int>> v, int start, int sum){
    if(start>n){ //퇴사 날짜를 넘기면 종료
        return;
    }
    ans=max(ans, sum); //원래 값, 갱신한 값 중 최대 수당 저장

    for(int i=start; i<n; i++) //start날짜 부터 시작하는 모든 경우의 수 탐색
        count(n, v,i+v[i].first, sum+v[i].second); 
        // i+v[i].first == 일 끝나는 날 == 새로 일 시작하는 날
        //sum+v[i].second==누적 수당

}

int main() {
    int n, temp;
    cin>>n;
    temp=n;

    vector<pair<int, int>> v;
    int t, p;
    while(temp--){
        cin>>t>>p;
        v.push_back(make_pair(t,p));
    }

    count(n,v,0,0);

    cout<<ans<<'\n';

}
