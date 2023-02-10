#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void bfs(vector<vector<int>>&graph, vector<vector<bool>>&visit, int x, int y, int n, int m){
    queue<pair<int,int>>q;
    q.push(make_pair(x,y));
    visit[x][y]=true;

    while(!q.empty()){
        int nx=q.front().first;
        int ny=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int cx=nx+dx[i];
            int cy=ny+dy[i];
            if(cx>=0 && cy>=0 && cx<n && cy<m && !visit[cx][cy] && graph[cx][cy]!=0){
                visit[cx][cy]=true;
                graph[cx][cy] = graph[nx][ny]+1; // 깊이 + 1
                q.push(make_pair(cx,cy));
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph(n,vector<int>(m,0));
    vector<vector<bool>>visit(n,vector<bool>(m,false));
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<m; j++){
            graph[i][j]=s[j]-'0';
        }
    }
    bfs(graph, visit, 0, 0, n, m);
    cout<<graph[n-1][m-1];
}
