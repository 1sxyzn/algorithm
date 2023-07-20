#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>>graph;
vector<bool>visit;

void bfs(int node){
    queue<int> q;
    visit[node]=true;
    q.push(node);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0; i<graph[now].size(); i++){
            if(!visit[graph[now][i]]){
                visit[graph[now][i]]==true;
                bfs(graph[now][i]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    graph.assign(n,vector<int>(0));
    visit.assign(n,false);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(computers[i][j]){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    for(int i=0; i<n; i++){
        if(!visit[i]){
            bfs(i);
            answer++;
        }
    }

    return answer;
}
