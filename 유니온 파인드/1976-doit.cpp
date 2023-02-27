#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>city;
vector<int>parent;
vector<int>route;

int find_set(int a){
    if(a==parent[a]) return a;
    else{
        parent[a]= find_set(parent[a]);
        return parent[a];
    }
}

void union_set(int a, int b){
    a= find_set(a);
    b= find_set(b);
    if(a!=b){
        parent[b]=a;
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    city.assign(n+1,vector<int>(n+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cin>>city[i][j];
    }

    parent.assign(n+1,0);
    for(int i=1; i<=n; i++) parent[i]=i;

    route.assign(m+1,0);
    for(int i=1; i<=m; i++){
        cin>>route[i];
    }

    // 모든 행렬 탐색하며 union
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(city[i][j]==1) union_set(i,j);
        }
    }

    // 모든 여행 도시의 대표 도시가 같은지 확인 (대표 도시가 같으면 같은 집합이므로)
    bool ans=true;
    for(int i=1; i<m; i++){
        if(find_set(route[i])!=find_set(route[i+1])){
            ans=false;
            break;
        }
    }
    if(ans) cout<<"YES";
    else cout<<"NO";
}
