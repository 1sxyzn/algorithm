#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>>v(n,{0,0});
        for(int i=0; i<n; i++) cin>>v[i].first>>v[i].second;
        sort(v.begin(), v.end());

        int ans=1; // 서류 1등 지원자
        int score=v[0].second; // 서류 1등 지원자의 면접 점수
        for(int i=1; i<n; i++){
            if(v[i].second<=score) { // 면접 점수 최고점 보다 면접 성적이 높으면 뽑기
                ans++;
                score = v[i].second; // 면점 점수 최고점 갱신
            }
        }
        cout<<ans<<'\n';
    }
}
