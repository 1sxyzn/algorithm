#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

/*
 * https://www.acmicpc.net/board/view/72995
 * 시작점이 어디든 상관 없이, 음수 cycle이 존재하는지 판단하면 되는 문제임
 * 또한 그래프가 하나로 연결되어 있다는 보장이 X
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin>>test;
    while(test--){
        int n,m,w;
        cin>>n>>m>>w;
        vector<tuple<int,int,int>>graph;
        vector<long long>dist(n+1, 1110987654321);

        int s,e,t;
        for(int i=0; i<m; i++){ // 도로
            cin>>s>>e>>t;
            graph.push_back({s,e,t});
            graph.push_back({e,s,t}); // 양방향
        }
        for(int i=0; i<w; i++){ // 웜홀
            cin>>s>>e>>t;
            graph.push_back({s,e,-t}); // 단방향
        }

        dist[1]=0; // 임의의 노드 1에서 부터 시작 (어디서 시작하든지 상관 x)

        int check = n-1;
        int a,b,c;
        while(check--){ // n-1번 반복
            for(int i=0; i<graph.size(); i++){ // 도로는 양방향에 웜홀은 단방향이라 i<2m+w나 graph.size() 해야함
                a = get<0>(graph[i]);
                b = get<1>(graph[i]);
                c = get<2>(graph[i]);

                if(dist[b] > dist[a] + c) dist[b] = dist[a] + c; // 거리가 무한대인지 여부 파악 X
                // 왜냐하면 1 - 2 -3 / 4- 5 -6 이런식으로 노드가 단절되어 있을 수도 있음
                // 이런 경우 1에서 출발할 때, 거리가 무한대인 것을 pass 할 경우 4 - 5 - 6 에서 음수 사이클 생기는지 판단 못함.
            }
        }

        // n번째 반복에서 cycle 여부 판단
        bool cycle = false;

        for(int i=0; i<graph.size(); i++){ // n번째 반복
            a = get<0>(graph[i]);
            b = get<1>(graph[i]);
            c = get<2>(graph[i]);

            if(dist[b] > dist[a] + c) cycle = true;
        }

        if(!cycle){
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<'\n';
        }
    }
}
