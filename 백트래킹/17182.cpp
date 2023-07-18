#include<iostream>
#include<vector>

using namespace std;

// floyd + dfs

vector<vector<int>>graph;
vector<bool>visit;
int ans = 987654321;
int n,k;

void dfs(int start, int dist, int cnt){
    if(ans < dist) return; //새로 구한 거리가, 이미 구한 거리보다 클 경우
    if(cnt == n) { // 모든 행성 다 방문함
        ans = min(ans, dist); //새로 구한 모든 노드 방문한 거리가, 이미 구한 거리보다 작은 경우
        return;
    }
    for(int i=0; i<n; i++){ // 전체 노드 중, 방문 안 한 노드 dfs
        if(visit[i]) continue;
        visit[i] = true;
        dfs(i, dist + graph[start][i], cnt+1);
        visit[i] = false; // 백트래킹
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    graph.assign(n,vector<int>(n,-1));
    visit.assign(n,false);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }

    // floyd
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]) graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    //dfs
    visit[k] = true;
    dfs(k,0,1); // 출발 행성, 총 거리, 방문 행성 갯수
    cout<<ans;
}
