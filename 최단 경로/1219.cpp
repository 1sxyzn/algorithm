#include<iostream>
#include<vector>
#include<climits>
#include<tuple>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,start,end;
    cin>>n>>start>>end>>m;

    vector<tuple<int,int,int>>v;
    vector<long long>dist(n,LONG_LONG_MIN);
    vector<long long>money(n,0); // 도시 별 수입

    for(int i=0; i<m; i++){
        int s,e,spend;
        cin>>s>>e>>spend;
        v.push_back({s,e,spend});
    }

    for(int i=0; i<n; i++){
        cin>>money[i];
    }

    // 벨만포드 시작
    dist[start]=money[start];
    for(int i=0; i<n+50; i++){ // 양수 사이클 있으려면 전파 시키려고 큰 수로 반복
        for(int j=0; j<m; j++){
            int s = get<0>(v[j]);
            int e = get<1>(v[j]);
            int spend = get<2>(v[j]);

            if(dist[s]==LONG_LONG_MIN) continue; // 시작 노드로부터 갈 루트가 없다면,,
            else if(dist[s]==LONG_LONG_MAX) dist[e]=LONG_LONG_MAX; // 양수 사이클이 생겼으면 Gee 출력하기 위해,,
            else if(dist[e] < dist[s]+money[e]-spend){ // 사이클은 없지만 더 많이벌 수 있는 루트 발견하면 갱신
                dist[e]=dist[s]+money[e]-spend;

                if(i>=n-1){
                    dist[e]=LONG_LONG_MAX; // 간선 n개 이상째면 cycle 존재
                }
            }
        }
    }

    if(dist[end]==LONG_LONG_MIN){
        cout<<"gg";
    }
    else if(dist[end]==LONG_LONG_MAX){
        cout<<"Gee";
    }
    else{
        cout<<dist[end];
    }
}
