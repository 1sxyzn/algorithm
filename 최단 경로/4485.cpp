#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int main(){
    int cnt=1;
    while(true){
        int n;
        cin>>n;
        if(n==0) break;
        vector<vector<bool>>visit(n,vector<bool>(n,false));
        vector<vector<int>>rupee(n,vector<int>(n,987654321));
        vector<vector<int>>graph(n,vector<int>(n,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>graph[i][j];
            }
        }

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>>q;
        rupee[0][0] = graph[0][0];
        q.push({rupee[0][0], {0,0}});
        while(!q.empty()){
            int cx = q.top().second.first;
            int cy = q.top().second.second;
            q.pop();

            if(visit[cx][cy]) continue;
            visit[cx][cy] = true;

            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    int nw = graph[nx][ny];
                    if(rupee[nx][ny] > rupee[cx][cy] + nw){
                        rupee[nx][ny] = rupee[cx][cy] + nw;
                        q.push({rupee[nx][ny], {nx,ny}});
                    }
                }
            }
        }
        cout<<"Problem "<<cnt<<": "<<rupee[n-1][n-1]<<'\n';
        cnt++;
    }
}
