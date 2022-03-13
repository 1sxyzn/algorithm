#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<cmath> //루트 계산

using namespace std;

//float는 범위가 작으므로 double 사용
typedef pair<double,double> dd;
typedef tuple<double,int,int> dii;

vector<int> parent;

int findParent(int x){
    if(parent[x]<0) //x가 루트이면
        return x; //x 리턴
    // 그래프 압축하면서 루트 찾기
    return parent[x]= findParent(parent[x]);
}

bool unionStar(int a, int b){
    int ap= findParent(a);
    int bp= findParent(b);

    if(ap==bp) //부모가 같으면 연결시 사이클 발생
        return false; //유니온 불가

    if(parent[ap]<parent[bp]){ //ap에 더 많은 자식이 있다면
        parent[ap]+=parent[bp];
        parent[bp]=ap;
    }
    else{
        parent[bp]+=parent[ap];
        parent[ap]=bp;
    }
    return true;
}

double kruskal(int v, priority_queue<dii, vector<dii>, greater<>>&pq){
    int cnt=0; //간선의 갯수
    double sum=0; //별의 거리의 총합

    while(cnt<v-1){ //크루스칼의 경우 정점이 v개 일 때, 간선의 수는 v-1이 됨
        double weight = get<0>(pq.top());
        int x = get<1>(pq.top());
        int y = get<2>(pq.top());
        pq.pop();

        if(unionStar(x,y)){ //별을 이을 수 있다면
            cnt++; //간선 추가
            sum+=weight; //별의 거리 누적해서 더하기
        }
   }
    return sum;
}

int main(){
    int n;
    cin>>n;

    priority_queue<dii,vector<dii>, greater<>> pq;
    parent.assign(n,-1);
    vector<dd> star(n);

    for(int i=0; i<n; i++)
        cin>>star[i].first>>star[i].second;

    //거리 구해서 짧은 거리부터 큐에 저장
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            double x = star[i].first - star[j].first;
            double y = star[i].second - star[j].second;
            pq.push({sqrt(x*x+y*y),i,j});
        }
    }
    //소수점 아래 두자리수 까지 출력
    cout<<fixed;
    cout.precision(2);

    cout<<kruskal(n,pq);
}
