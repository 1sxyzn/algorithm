#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;
    while(t--){
        int n,d,c; // 컴퓨터 수, 의존성 수, 시작 컴퓨터 번호
        cin>>n>>d>>c;
        vector<vector<pair<int,int>>>graph(n+1, vector<pair<int,int>>(0));
        vector<int>dist(n+1,987654321);
        vector<bool>visit(n+1,false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>q;

        while(d--){
            int a,b,s;
            cin>>a>>b>>s;
            graph[b].push_back({a,s}); // 방향 주의
        }

        q.push({0, c});
        dist[c]=0;
        while(!q.empty()){
            int cur_node = q.top().second;
            q.pop();
            if(visit[cur_node]) continue;
            visit[cur_node] = true;

            for(int i=0; i<graph[cur_node].size(); i++){
                int next_node = graph[cur_node][i].first;
                int next_weight = graph[cur_node][i].second;

                if(dist[next_node] > dist[cur_node] + next_weight){
                    dist[next_node] = dist[cur_node] + next_weight;
                    q.push({dist[next_node], next_node});
                }
            }
        }

        int cnt=0, MAX=0;
        for(int i=1; i<=n; i++){
            if(dist[i]!=987654321){
                cnt++;
                MAX = max(MAX, dist[i]);
            }
        }
        cout<<cnt<<' '<<MAX;
        cout<<'\n';
    }
}
