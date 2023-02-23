#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

vector<tuple<int,int,int>>v[10];
vector<long long>w; // 노드 별 가중치 저장
vector<bool>visit;

void dfs(int node){
    visit[node]=true;
    for(int i=0; i<v[node].size(); i++){
        int next_node = get<0>(v[node][i]);
        if(!visit[next_node]){
            w[next_node] = w[node] * get<2>(v[node][i]) / get<1>(v[node][i]); // 정리하면 b = a*q/p 라는 값이 나옴
            dfs(next_node);
        }
    }
}

long long gcd(long long a, long long b){ //greatest common divisor
    if(b==0) return a;
    else return gcd(b, a%b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    w.assign(n,0);
    visit.assign(n,false);

    long long lmc=1; //least common multiple
    for(int i=0; i<n-1; i++){
        int a,b,p,q;
        cin>>a>>b>>p>>q;
        v[a].push_back({b,p,q});
        v[b].push_back({a,q,p});
        lmc *= (p*q / gcd(p,q)); // 모든 수의 최소 공배수 구하기
    }

    // 0번 노드부터 dfs 시작
    w[0]=lmc;
    dfs(0);

    long long gcd_value=w[0];
    for(int i=1; i<n; i++){
        gcd_value= gcd(gcd_value, w[i]); // 노드들의 각 값이 최소 비율의 n 배 된거라면, 그 n 을 찾아야함
    }

    for(int i=0; i<n; i++){
        cout<<w[i]/gcd_value<<' '; // 전체 값이, n배 된 값이라면 /n을 해서 출력
    }
}
