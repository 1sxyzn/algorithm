#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> indegree; //진입차수. 0되면 큐에 push
vector<int> delay; //건설시 걸리는 시간
vector<vector<int>> graph; //인접 리스트

//위상정렬 + dp
int topologicalSort(int n, int w){
    queue<int> q;
    vector<int> dp(n+1,0); //건물 짓기 위한 최소시간 저장할 dp배열

    for(int i=1; i<=n; i++){
        dp[i]=delay[i]; //각자 건물 짓는데 걸리는 시간으로 dp 초기화
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0; i<graph[x].size(); i++) {
            int next = graph[x][i];
            indegree[next]--;

            if(indegree[next]==0)
                q.push(next);

            // 다른 경로와, 이전 건물을 짓고 해당 건물을 짓는 경로 중 더 오래 걸리는걸 택
            // 더 적게 걸리는 경로를 택하면 같은 선상의 다른 건물은 미완인 상태.
            dp[next]=max(dp[next],dp[x] + delay[next]);
        }
    }
    return dp[w];
}

int main(){
    int t, n, k, x, y, w;
    cin>>t; //테스트 케이스 갯수
    while(t--){
        cin>>n>>k; //건물 갯수, 규칙 갯수
        indegree.assign(n+1,0);
        delay.assign(n+1,0);
        graph.assign(n+1, vector<int>(0));

        for(int i=1; i<=n; i++)
            cin>>delay[i];

        //규칙을 그래프에 저장
        while(k--){
            cin>>x>>y; //x->y 이므로 y의 진입차수 ++
            indegree[y]++;
            graph[x].push_back(y);
        }

        cin>>w; //건물 w 건설하기 위한 최소 시간 찾기
        cout<<topologicalSort(n, w)<<'\n';
    }
}
