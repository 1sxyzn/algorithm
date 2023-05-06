#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int mx[6] = {1,-1,0,0,0,0};
int my[6] = {0,0,-1,1,0,0};
int mz[6] = {0,0,0,0,-1,1};

vector<vector<vector<int>>>box;
queue<pair<int,pair<int,int>>> q;
int m,n,h;

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;
        q.pop();
        for(int i=0; i<6; i++){
            int nx = x+mx[i];
            int ny = y+my[i];
            int nz = z+mz[i];
            if(nx>=0 && nx<h && ny>=0 && ny<n && nz>=0 && nz<m && box[nx][ny][nz]==0){
                box[nx][ny][nz] = box[x][y][z]+1;
                q.push({nx,{ny,nz}});
            }
        }
    }
}

int main(){
    cin>>m>>n>>h;
    box.assign(h, vector<vector<int>>(n,vector<int>(m,-1)));
    int no_red=0; // x = 높이, yz = 가로, 세로
    for(int i=0; i<h;i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin>>box[i][j][k];
                if(box[i][j][k]==1) q.push({i,{j,k}});
                else if(box[i][j][k]==0) no_red++;
            }
        }
    }

    bfs();

    int ans=0;
    for(int i=0; i<h;i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(box[i][j][k]==0){
                    cout<<-1;
                    return 0;
                }
                else ans = max(ans, box[i][j][k]);
            }
        }
    }
    cout<<ans-1;
}
