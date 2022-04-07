#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int bfs(vector<vector<int>> graph, int n){
    queue<int>q;
    vector<bool> visited(n+1,false);
    int ans=0;

    q.push(1); //정점 1부터 시작
    visited[1]=true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=1; i<=n; i++){
            if(graph[node][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
                ans++;
            }
        }
    }

    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> graph(n+1,vector<int>(n+1,0));
    int a,b;
    while(m--){
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }

    cout<<bfs(graph, n)<<'\n';
}
