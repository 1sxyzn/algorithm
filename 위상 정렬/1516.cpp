#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>>building(n+1,vector<int>(0));
    vector<int>indegree(n+1,0);
    vector<int>firstTime(n+1,0);
    vector<int>ans(n+1,0);

    for(int i=1; i<=n; i++){
        int a;
        cin>>firstTime[i];
        while(true){
            cin>>a;
            if(a==-1) break;
            building[a].push_back(i);
            indegree[i]++;
        }
    }

    queue<int>q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0; i<building[node].size(); i++){
            indegree[building[node][i]]--;
            ans[building[node][i]]=max(ans[building[node][i]], ans[node]+firstTime[node]); // 해당 건물을 짓기 위해 가장 오래 걸린 시간을 찾기
            if(indegree[building[node][i]]==0) q.push(building[node][i]);
        }
    }

    for(int i=1; i<=n; i++){
        cout<<ans[i]+firstTime[i]<<'\n';
    }
}
