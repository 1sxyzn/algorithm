#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<int>parent;
vector<vector<long long>>dot;

int find(int node){
    if(parent[node]<0) return node;
    else return parent[node] = find(parent[node]);
}

void union_set(int i, int j){
    int p1 = find(i);
    int p2 = find(j);

    if(p1 == p2) return; // 이미 같은 그룹
    else{
        parent[p1]+=parent[p2];
        parent[p2]=p1;
    }
}

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3){ // 외적
    long long result = (x1*y2+x2*y3+x3*y1) - (x2*y1+x3*y2+x1*y3);
    if(result>0) return 1;
    else if(result<0) return -1;
    else return 0;
}

bool isOverLab(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4){ // 선분 겹침 여부
    if(min(x1,x2)<=max(x3,x4) && min(x3,x4)<=max(x1,x2) && min(y1,y2)<=max(y3,y4) && min(y3,y4)<=max(y1,y2)) return true;
    else return false;
}

bool isCross(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4){ // 선분 교차 여부
    int abc = ccw(x1,y1,x2,y2,x3,y3);
    int abd = ccw(x1,y1,x2,y2,x4,y4);
    int cda = ccw(x3,y3,x4,y4,x1,y1);
    int cdb = ccw(x3,y3,x4,y4,x2,y2);

    if(abc*abd==0 && cda*cdb==0) return isOverLab(x1,y1,x2,y2,x3,y3,x4,y4); // 일직선상에 있으므로 겹치는지 확인하기
    else if(abc*abd<=0 && cda*cdb<=0) return true; // 외적 곱이 0이면 선분을 기준으로 점이 반대 구역에 있음 -> 두 선분이 겹칠 수 밖에 없음
    else return false;
}

int main(){
    int n; cin>>n;
    parent.assign(n+1,-1);
    dot.assign(n+1, vector<long long>(4,0));
    for(int i=1; i<=n; i++){
        cin>>dot[i][0]>>dot[i][1]>>dot[i][2]>>dot[i][3];
        for(int j=1; j<=i; j++){
            if(isCross(dot[i][0], dot[i][1], dot[i][2], dot[i][3], dot[j][0], dot[j][1], dot[j][2], dot[j][3])) union_set(i, j);
        }
    }

    int ans=0, node=0;
    for(int i=1; i<=n; i++){
        if(parent[i]<0){
            ans++;
            node = min(node, parent[i]); // 더 많은 자식을 가진 부모 노드 (자식 갯수는 parent에 음수로 저장됨)
        }
    }

    cout<<ans<<'\n'<<-node;
}
