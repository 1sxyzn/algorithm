#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// 빨리 시작하는 강의순으로 정렬한다.
// 큐에는 끝나는 시간을 저장한다.
// 가장 먼저 끝나는 강의 다음에, 다음 강의가 올 수 있으면 큐 값 갱신
// 겹치는 관계로 다음 강의가 오지 못하면 강의실 (큐) 추가
// 벡터로 하면 시간초과. 우선순위 큐 쓰자

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first!=b.first)
        return a.first<b.first;
    return a.second<b.second;
}

int count(vector<pair<int, int>> lec, int n) {
    priority_queue<int, vector<int>, greater<int>> room;
    int ans=1;
    room.push(lec[0].second);
    for(int i=1; i<n; i++){
        if(room.top()<=lec[i].first)
            room.pop();
        else
            ans++;
        room.push(lec[i].second);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> lec;
    int a, b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        lec.push_back(make_pair(a,b));
    }
    sort(lec.begin(), lec.end(), cmp);
    cout<<count(lec, n)<<'\n';
}
