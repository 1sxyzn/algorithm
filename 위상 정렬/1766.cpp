#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<vector<int>>graph(n+1, vector<int>(0));
    vector<int>indegree(n+1,0);

    int a,b;
    while(m--){
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    priority_queue<int, vector<int>, greater<>>pq;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0)
            pq.push(i);
    }

    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        cout<<cur<<' ';
        for(int i=0; i<graph[cur].size(); i++){
            indegree[graph[cur][i]]--;
            if(indegree[graph[cur][i]]==0) pq.push(graph[cur][i]);
        }
    }
}
