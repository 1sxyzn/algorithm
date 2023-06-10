#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>singer(n+1, vector<int>(0));
    vector<int>indegree(n+1,0);
    vector<int>ans;

    while(m--){
        int cnt; cin>>cnt;
        int bef, aft; cin>>bef;
        cnt--;
        while(cnt--){
            cin>>aft;
            singer[bef].push_back(aft);
            indegree[aft]++;
            bef = aft;
        }
    }

    queue<int>q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(int i=0; i<singer[cur].size(); i++){
            indegree[singer[cur][i]]--;
            if(indegree[singer[cur][i]]==0) q.push(singer[cur][i]);
        }
    }
    if(ans.size() == n){
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]<<'\n';
        }
    }
    else
        cout<<'0';
}
