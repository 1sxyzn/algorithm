#include<vector>
#include<queue>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n, m;

vector<vector<int>>visit;

void bfs(vector<vector<int>>maps){
    queue<pair<int,int>>q;
    q.push({0,0});
    visit[0][0]=1;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && visit[nx][ny]==0 && maps[nx][ny]==1){
                visit[nx][ny] = visit[cx][cy] + 1;
                q.push({nx,ny});
            }
        }
    }
}

int solution(vector<vector<int>> maps){
    n = maps.size();
    m = maps[0].size();
    visit.assign(n, vector<int>(m,0));

    bfs(maps);

    if(visit[n-1][m-1]==0) return -1;
    else return visit[n-1][m-1];
}
