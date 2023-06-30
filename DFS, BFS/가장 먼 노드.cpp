#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    //BFS 
    queue<int>q;
    vector<bool>visit(n+1,false);
    vector<int>dist(n+1,0);
    vector<vector<int>>graph(n+1, vector<int>(0));
    
    for(int i=0; i<edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    int MAX=0;
    q.push(1);
    visit[1]=true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i=0; i<graph[cur].size(); i++){
            if(!visit[graph[cur][i]]){
                q.push(graph[cur][i]);
                dist[graph[cur][i]] = dist[cur]+1;
                visit[graph[cur][i]] = true;
                MAX = max(MAX, dist[graph[cur][i]]);
            }
        }
    }
    
    int answer = 0;
    for(int i=1; i<=n; i++){
        if(dist[i] == MAX) answer++;
    }
    return answer;
}
