#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>>ground;
vector<vector<bool>>visit;
int ans, n, m;

int mx[4] = {0,0,1,-1};
int my[4] = {1,-1,0,0};

void bfs(int x, int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    visit[x][y]=true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            // 범위 확인하고 -> 방문 + 값 확인하기 // 방문 + 값 부터 확인하면 인덱스 오류 남
            if(cx+mx[i]>=0 && cx+mx[i]<n && cy+my[i]>=0 && cy+my[i]<m && !visit[cx+mx[i]][cy+my[i]] && ground[cx+mx[i]][cy+my[i]]==1){
                q.push({cx+mx[i], cy+my[i]});
                visit[cx+mx[i]][cy+my[i]]=true;
            }
        }
    }
}

int main(){
    int t, k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        ans=0;
        ground.assign(n, vector<int>(m,0));
        visit.assign(n, vector<bool>(m,false));
        int x,y;
        while(k--){
            cin>>x>>y;
            ground[x][y]=1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(ground[i][j]==1 && !visit[i][j]) {
                    bfs(i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
