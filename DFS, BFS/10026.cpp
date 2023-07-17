#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<char>>graph_rg_diff;
vector<vector<char>>graph_rg_same;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int n;

void bfs(int x, int y, char c, bool rg_same){
    queue<pair<int,int>>q;
    q.push({x,y});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n){ // rg_same이 true이면 r-g를 같은 것 취급, b는 다른 것 취급
                if(rg_same){
                    if(graph_rg_same[nx][ny]!='N'){ // 방문한 것이 아니라면
                        // 현재 구역과 해당 칸이 달라도 R과 G는 같은 것 취급 || // 현재 구역과 해당 칸이 같으면
                        if((c!='B' && graph_rg_same[nx][ny]!='B') || (c=='B' && graph_rg_same[nx][ny]=='B')){
                            q.push({nx,ny});
                            graph_rg_same[nx][ny] ='N'; // 방문한 것으로 변경
                        }
                    }
                }

                // rg_same이 false면 r-g-b를 다른 것 취급
                else{
                    if(graph_rg_diff[nx][ny]!='N'){ // 방문한 것이 아니라면
                        if(c == graph_rg_diff[nx][ny]){ // 현재 구역과 해당 칸이 같으면
                            q.push({nx,ny});
                            graph_rg_diff[nx][ny] ='N'; // 방문한 것으로 변경
                        }
                    }
                }
            }
        }
    }
}

int main(){
    cin>>n;
    graph_rg_diff.assign(n,vector<char>(n,'N'));
    graph_rg_same.assign(n,vector<char>(n,'N'));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>graph_rg_diff[i][j];
            graph_rg_same[i][j] = graph_rg_diff[i][j];
        }
    }

    int rg_diff = 0;
    int rg_same = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(graph_rg_same[i][j]!='N'){
                bfs(i, j, graph_rg_same[i][j], true);
                rg_same++;
            }
            if(graph_rg_diff[i][j]!='N'){
                bfs(i, j, graph_rg_diff[i][j], false);
                rg_diff++;
            }
        }
    }

    cout<<rg_diff<<" "<<rg_same;
}
