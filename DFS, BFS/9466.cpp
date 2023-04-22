#include<iostream>
#include<vector>

using namespace std;

vector<int>member;
vector<bool>visit;
vector<bool>group;
int ans;

void dfs(int mem){
    visit[mem] = true;
    int want = member[mem];
    if(!visit[want]) dfs(want);

    // 방문한 경우 (사이클 생성)
    else {
        if(!group[want]){ // 방문 했는데 그룹이 안 정해졌다면
            // 사이클 사이의 팀원이 몇 명인지 카운트
            for(int i=want; i!=mem; i=member[i]){
                ans++;
            }
            ans++; // mem, 즉 자기 자신도 카운드
        }
    }
    group[mem] = true; // 그룹 생성 완료
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ans=0;
        int n;
        cin>>n;
        member.assign(n+1,0);
        visit.assign(n+1,false);
        group.assign(n+1,false);
        for(int i=1; i<=n; i++) cin>>member[i];
        for(int i=1; i<=n; i++) dfs(i);
        cout<<n - ans<<'\n';
    }
}
