#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

int main(){
    int tc, cnt=1;
    cin>>tc;
    while(tc--){
        int m,n;
        cin>>m>>n;
        vector<vector<pair<int,int>>>graph(n);
        vector<int>dist(n,100);
        vector<bool>visit(n,false); // 방문여부
        vector<int>pre_node(n,-1); // 이전 노드 저장
        int u,v,w;
        while(m--){
            cin>>u>>v>>w;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
        q.push({0,0});
        dist[0] = 0;
        while(!q.empty()){
            int node = q.top().second;
            q.pop();
            if(visit[node]) continue;
            visit[node] = true;

            for(int i=0; i<graph[node].size(); i++){
                int next = graph[node][i].first;
                int next_w = graph[node][i].second;
                if(dist[next] > dist[node] + next_w){
                    dist[next] = dist[node] + next_w;
                    q.push({dist[next], next});
                    pre_node[next] = node; // 이전 노드 저장 - 역추척 할 예정
                }
            }
        }

        cout<<"Case #"<<cnt<<": ";
        if(dist[n-1]==100) cout<<-1; // 최고의원한테 도달 X

        else{
            stack<int>ans;
            int back = n-1;
            while(back != 0){
                ans.push(back);
                back = pre_node[back];
            }

            cout<<"0 ";
            while(!ans.empty()){
                cout<<ans.top()<<" ";
                ans.pop();
            }
        }

        cout<<'\n';
        cnt++;
    }
}
