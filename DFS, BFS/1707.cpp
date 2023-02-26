#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>graph;
vector<bool>visit;
vector<char>group;
bool ans;

void dfs(int node){
    visit[node]=true;

    for(int i=0; i<graph[node].size(); i++){
        if(!visit[graph[node][i]]){ // 방문 안했으면 다른 그룹으로 check
            if(group[node]=='A') group[graph[node][i]]='B';
            else group[graph[node][i]]='A';
            dfs(graph[node][i]);
        }
        else if(group[node]==group[graph[node][i]]){ // 방문했던 노드인데 연결된 두 노드가 같은 집합이면 이분 그래프 X
            ans=false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        ans=true;
        int v, e;
        cin >> v >> e; // 정점, 간선
        graph.assign(v + 1, vector<int>(0));
        group.assign(v + 1, 'A');
        visit.assign(v + 1, false);

        int start, end;
        for (int i = 0; i < e; i++) {
            cin >> start >> end;
            graph[start].push_back(end);
            graph[end].push_back(start);
        }

        //모든 노드에서 수행 (모든 노드들이 연결이 안되어 있을 수도)
        for (int i = 1; i <= v; i++) {
            if (ans) dfs(i);
            else break;
        }

        if (ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
