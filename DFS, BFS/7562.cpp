#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<vector<int>>graph;
pair<int,int>start;
pair<int,int>goal;
int mx[8] = {-2,-1,1,2,-2,-1,1,2};
int my[8] = {1,2,2,1,-1,-2,-2,-1};
int n;

void bfs(pair<int,int> cur){
    queue<pair<int,int>>q;
    q.push(cur);
    graph[cur.first][cur.second]++;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<8; i++){
            int nx = cx+mx[i];
            int ny = cy+my[i];
            if(0<=nx && nx<n && 0<=ny && ny<n && graph[nx][ny]<0){
                graph[nx][ny] = graph[cx][cy] + 1;
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        graph.assign(n, vector<int>(n,-1));

        cin>>start.first>>start.second;
        cin>>goal.first>>goal.second;
        bfs(start);
        cout<<graph[goal.first][goal.second]<<'\n';
    }
}
