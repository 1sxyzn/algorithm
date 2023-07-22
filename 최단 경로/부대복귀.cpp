#include <string>
#include <vector>
#include <queue>

using namespace std;

// dest 에서 다익스트라 돌리고 source 까지의 최단거리 구하기
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>>graph(n+1);
    vector<int>dist(n+1,987654321);
    vector<int>visit(n+1,false);

    for(int i=0; i<roads.size(); i++){
        graph[roads[i][0]].push_back(roads[i][1]);
        graph[roads[i][1]].push_back(roads[i][0]);
    }

    queue<int> q;
    q.push(destination);
    dist[destination]=0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(visit[cur]) continue; // 방문 한 노드일 경우
        visit[cur]=true;

        for(int i=0; i<graph[cur].size(); i++){
            int next = graph[cur][i];
            if(dist[next] > dist[cur]+1) {
                dist[next] = dist[cur]+1;
                q.push(next);
            }
        }
    }

    for(int i=0; i<sources.size(); i++){
        if(dist[sources[i]]==987654321) answer.push_back(-1);
        else answer.push_back(dist[sources[i]]);
    }

    return answer;
}
