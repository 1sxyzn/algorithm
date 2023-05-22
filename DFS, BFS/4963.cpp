#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> island;

int w,h;
int dw[8]={-1,0,1,-1,1,-1,0,1};
int dh[8]={1,1,1,0,0,-1,-1,-1};
// 0 1 2
// 3   4
// 5 6 7

void bfs(int height, int width){
    queue<pair<int,int>>q;
    q.push({height,width});
    island[height][width]=0;
    while(!q.empty()){
        int ch = q.front().first;
        int cw = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int nh = ch + dh[i];
            int nw = cw + dw[i];
            if(nh>=0 && nh<h && nw>=0 && nw<w && island[nh][nw]==1){
                island[nh][nw]=0; // 방문하면 0으로 바꿔버리기
                q.push({nh, nw});
            }
        }
    }
}

int main(){
    while(true){
        cin>>w>>h;
        if(w==0 && h==0) break;
        island.assign(h,vector<int>(w,0));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>island[i][j];
            }
        }
        // bfs
        int ans=0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(island[i][j]==1){
                    bfs(i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
