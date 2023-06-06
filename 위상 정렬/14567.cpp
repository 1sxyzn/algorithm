#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<int>ans(n+1,0); // 정답 저장
    vector<vector<int>>graph(n+1,vector<int>(0)); // 선수 과목들 저장
    vector<int>indegree(n+1,0); // 진입차수

    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int>q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0) {
            q.push(i); // 1학기에 들을 수 있는 것들
            ans[i]=1;
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<graph[cur].size(); i++){
            indegree[graph[cur][i]]--;
            ans[graph[cur][i]] = ans[cur]+1;
            if(indegree[graph[cur][i]]==0) q.push(graph[cur][i]);
        }
    }
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<' ';
    }
}
