#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v,e,start;
    cin>>v>>e>>start;
    vector<vector<pair<int,int>>>graph(v+1,vector<pair<int,int>>(0));
    vector<int>ans(v+1, INT_MAX);
    vector<bool>started(v+1,false);
    priority_queue<pair<int,int>>q;

    int a,b,w;
    for(int i=0; i<e; i++){
        cin>>a>>b>>w;
        graph[a].push_back({w,b});
    }

    q.push({0, start}); // 큐에는 거리순으로 저장하고 싶으므로 pair의 fisrt가 거리
    ans[start]=0;
    while(!q.empty()){
        pair<int,int>cur=q.top();
        q.pop();
        if(started[cur.second]) continue; // 해당 정점을 시작으로 탐색했었으면 pass

        started[cur.second]=true;
        for(int i=0; i<graph[cur.second].size(); i++){
            int node = graph[cur.second][i].second;
            int weight = graph[cur.first][i].first;
            if(ans[node]>ans[cur.second]+weight){ // 경유해서 더 짧은 거리로 갈 수 있다면
                ans[node]=ans[cur.second]+weight;
                q.push({ans[node],node}); // 갱신 된 결과를 기반으로 가까운 노드부터 다시 탐색
            }
        }
    }

    for(int i=1; i<=v; i++){
        if(started[i]) cout<<ans[i]<<'\n';
        else cout<<"INF"<<'\n';
    }
}
