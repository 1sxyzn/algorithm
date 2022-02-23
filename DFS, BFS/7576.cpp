#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//bfs 풀이
int bfs(int n, int m, int total, vector<vector<int>> tomato, queue<pair<int,int>>q){
    //상 하 좌 우
    int r[4]={-1, 1, 0, 0};
    int c[4]={0, 0, -1, 1};
    //r과 c가 index =0 이라면 (-1,0)이고 행을 -1, 열을 0 만큼 이동하면 위(상)로 움직이게 됨
    //r과 c가 index =2 이라면 (0,-1)이고 행을 0, 열을 -1 만큼 이동하면 왼쪽(좌)로 움직이게 됨 (ex. 2,2 -> 2,1)
    int time=0; //토마토 익는데 걸리는 시간

    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        total--;
        time=tomato[row][col]; //현재 칸에, 현재 토마토까지 도달하는데에 걸린 시간 저장되어있음

        for(int i=0; i<4; i++){ //토마토에 인접한 상,하,좌,우 보기 위함
            int row_around = row + r[i];
            int col_around = col + c[i];
            //상 or 하 or 좌 or 우 를 보는 중인데 해당 좌표가 범위를 벗어나지 않고, 그곳에 토마토가 있다면
            if(row_around<=n && row_around >0 && col_around<=m && col_around >0 && tomato[row_around][col_around]==0){
                tomato[row_around][col_around] = tomato[row][col]+1; // 인접 토마토 익음. 좌표를 도달 시간으로 변경
                q.push(make_pair(row_around,col_around));
            }
        }

        if(total==0){ //모든 토마토가 다 익으면
            return time-1; //익은 토마토 자리는 1, 첫날에 익게된 토마토는 여기서 +1해서 2가되었다. 첫날에 2, 둘째날에 3이므로 n째날은 time-1
        }

    }
    return -1; //토마토가 다 못익으면 -1 반환
}

int main(){
    int m,n;
    cin>>m>>n;
    int total = m*n; //모든 토마토 갯수

    queue<pair<int,int>>q; //익은 토마토 = 시작위치를 페어로 저장
    vector<vector<int>> tomato(n+1, vector<int>(m+1));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>tomato[i][j];
            if(tomato[i][j] == 1) //토마토가 익은거라면
                q.push(make_pair(i,j));
            else if(tomato[i][j] == -1) //토마토가 없다면
                total--;
        }
    }
    cout<<bfs(n,m,total,tomato,q)<<'\n';
}
