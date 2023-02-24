#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>>graph;
vector<bool>visit;
vector<int>trust;

void bfs(int node){
    queue<int>q;
    q.push(node);
    visit[node]=true;
    while(!q.empty()){
        int next = q.front();
        q.pop();
        for(int i=0; i<graph[next].size(); i++){
            if(!visit[graph[next][i]]){
                trust[graph[next][i]]++;
                q.push(graph[next][i]);
                visit[graph[next][i]]=true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    graph.assign(n+1,vector<int>(0));
    trust.assign(n+1,0);

    //A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.
    //A를 해킹한다고 B를 해킹할 수 있는건 아니다. => 단방향 그래프
    //신뢰 당하는(?) 횟수를 카운트 하자
    int a,b;
    while(m--){
        cin>>a>>b;
        // a가 b를 신뢰, b는 a에게 신뢰 당함
        // bfs 탐색 시 인접 리스트를 거쳐 b가 신뢰 당하는 횟수룰 count 하자
        graph[a].push_back(b);
    }
    for(int i=1; i<=n; i++){
        visit.assign(n+1,false);
        bfs(i);
    }
    int max=0;
    for(int i=1; i<=n; i++){
        if(trust[i]>max){
            max=trust[i];
        }
    }
    for(int i=1; i<=n; i++){
        if(trust[i]==max){
            cout<<i<<' ';
        }
    }
}
