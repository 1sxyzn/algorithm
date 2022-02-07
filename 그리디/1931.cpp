#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// 회의가 빨리 끝나는 순으로 정렬
// 끝나는 시간이 같으면 먼저 시작하는 순으로 정렬
// (늦게 시작하는 순으로 하면 4,6과 6,6이 있을 때 6,6만 배정됨. 빨리 시작하는 순으로 하면 4,6 6,6 모두 배정됨)
bool cmp(pair<int,int> a, pair<int, int> b){
    if(a.second!=b.second)
        return a.second<b.second; // 빨리 끝나는 순으로 정렬
    return a.first<b.first; // 끝나는 시간이 같으면 먼저 시작하는 순으로 정렬
}

int greedy(vector<pair<int, int>> meeting, int n){
    int end = meeting[0].second; //가장 빨리 끝나는 미팅 저장
    int ans=1; // 배정할 수 있는 회의실의 최댓값 저장
    for(int i=1; i<n; i++) {
        if(end <= meeting[i].first){ // 배정된 마지막 회의 이후에 시작하는 회의가 있다면
            end = meeting[i].second;
            ans++; //회의실 갯수 추가
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> meeting;

    int start, end;
    for(int i=0; i<n; i++){
        cin>>start>>end;
        meeting.push_back(make_pair(start, end));
    }

    sort(meeting.begin(), meeting.end(), cmp);
    cout<<greedy(meeting, n)<<'\n';
}
