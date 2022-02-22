#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<bool>>mat;
vector<bool>visited;

//dfs - 재귀함수로 구현
void dfs(int n, int v){
    if(visited[v])
        return;

    visited[v]=true;
    cout<<v<<' ';
    for(int i=1; i<=n; i++){
        if(mat[v][i])
            dfs(n,i);
    }
}

//bfs
vector<int> bfs(int n, int v){
    vector<int> ans;
    queue<int> q;

    q.push(v); //처음 정점 저장
    visited[v]=true;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);

        for(int i=1; i<=n; i++){
            if(mat[node][i] && !visited[i]){
                visited[i]=true;
                q.push(i);
            }
        }
    }

    return ans;
}

int main(){
    int n,m,v,a,b;
    cin>>n>>m>>v;
    mat.assign(n+1, vector<bool>(n+1));
    for(int i=0; i<m; i++){
        cin>>a>>b;
        mat[a][b]=mat[b][a]=true;
    }

    //dfs
    visited.assign(n+1,false);
    dfs(n,v);
    cout<<'\n';

    //bfs
    visited.assign(n+1,false);
    vector<int> bfs_ans = bfs(n,v);
    for(int i=0; i<bfs_ans.size(); i++)
        cout<<bfs_ans[i]<<' ';
}
