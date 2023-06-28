#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>graph(n+1,vector<int>(n+1, 987654321));
        for(int i=0; i<=n; i++) graph[i][i]=0; // 자기 자신 초기화. 빼먹어서 틀렸습니다 떴었음

        while(m--){
            int a,b,c;
            cin>>a>>b>>c;
            graph[a][b]=c;
            graph[b][a]=c;
        }

        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(graph[i][j] > graph[i][k] + graph[k][j]) graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }

        int friend_num;
        cin>>friend_num;
        vector<int>friends;
        for(int i=0; i<friend_num; i++) {
            int f;
            cin>>f;
            friends.push_back(f);
        }

        // graph[친구n][j] 의 합이 최소인 j 찾기
        int ans=-1;
        int dist=987654321;
        for(int i=1; i<=n; i++){
            int temp = 0;
            for(int j=0; j<friend_num; j++){
                temp += graph[friends[j]][i];
            }
            if(dist > temp){
                dist = temp;
                ans = i;
            }
        }

        cout<<ans<<'\n';
    }
}
