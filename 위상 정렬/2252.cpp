#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>indegree; //진입차수 저장, 진입차수 0이면 큐에 push할 예정
vector<vector<int>>graph; //인접 리스트

vector<int> topologicalSort(int n){
    vector<int>ans;
    queue<int>q;

    for(int i=1; i<=n; i++){
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        int x=q.front();
        q.pop();
        ans.push_back(x);

        for(int i=0; i<graph[x].size(); i++){
            int next = graph[x][i];
            indegree[next]--;
            if(indegree[next]==0)
                q.push(next);
        }
    }
    return ans;
}

int main(){
    int n,m,a,b;
    cin>>n>>m;
    indegree.assign(n+1,0);
    graph.assign(n+1,vector<int>(0));
    while(m--){
        //a학생이 b학생 앞에 서야함
        cin>>a>>b;
        indegree[b]++; //a->b이므로 b의 진입차수 증가
        graph[a].push_back(b);
    }

    vector<int> ans = topologicalSort(n);

    for(int i=0; i<n; i++)
        cout<<ans[i]<<' ';
    cout<<'\n';
}
