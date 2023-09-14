#include<iostream>
#include<vector>

using namespace std;

// 주변 칸 청소하기 위한 방향
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
// 0: 북, 1: 동, 2: 남, 3: 서
// r-1, c+1, r+1, c-1

vector<vector<int>>room;
int n,m,ans=0;

// 0: 청소되지 않은 빈칸, 1: 벽, 2: 청소된 칸
void cleaning(int r, int c, int d){
    if(0<=r && r<n && 0<=c && c<m && room[r][c]==0){
        room[r][c] = 2;
        ans++;
    }
    int nr, nc;
    bool flag = false;
    for(int i=0; i<4; i++){
        nr = r + dx[(d+3-i)%4];
        nc = c + dy[(d+3-i)%4];
        if(0<=nr && nr<n && 0<=nc && nc<m && room[nr][nc]==0) { // 빈칸이 있는 경우 체크
            // 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
            cleaning(nr, nc, (d+3-i)%4);
            flag = true;
            break;
        }
    }
    if(!flag){
        // 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
        nr = r + dx[(d+2)%4];
        nc = c + dy[(d+2)%4];
        if(0<=nr && nr<n && 0<=nc && nc<m && room[nr][nc]!=1){
            cleaning(nr,nc,d);
        }
        // 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
        else return;
    }
}

int main(){
    int r,c,d;
    cin>>n>>m>>r>>c>>d;
    room.assign(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>room[i][j];
        }
    }
    cleaning(r,c,d);
    cout<<ans;
}
