#include<iostream>
#include<vector>

using namespace std;

vector<int>present;
vector<int>truer;
vector<vector<int>>party;
int result=0;

int find_set(int a){
    if(a==present[a]) return a;
    else {
        present[a]= find_set(present[a]);
        return present[a];
    }
}

void union_set(int a, int b){
    a= find_set(a);
    b= find_set(b);
    if(a!=b){
        present[b]=a;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m; cin>>n>>m; // 사람수 파티수

    // 진실을 아는 사람
    int t; cin>>t; truer.assign(t+1,0);
    for(int i=1; i<=t; i++){
        cin>>truer[i];
    }

    // 파티 정보
    party.assign(m+1,vector<int>(0));
    int people, num;
    for(int i=1; i<=m; i++){
        cin>>people;
        for(int j=0; j<people; j++){
            cin>>num;
            party[i].push_back(num);
        }
    }

    // 대표 노드 초기화
    present.assign(n+1,0);
    for(int i=1; i<=n; i++){
        present[i]=i;
    }

    int cur_present;
    // 한 파티에 참여한 사람들을 한 집합으로 union
    for(int i=1; i<=m; i++){
        cur_present = party[i][0]; // 파티의 대표 노드
        for(int j=0; j<party[i].size(); j++){
            union_set(cur_present, party[i][j]);
        }
    }

    // 진실을 아는 사람이 있는 파티는 과장 x
    for(int i=1; i<=m; i++){ // 모든 파티의 대표 노드 탐색하면서 해당 파티에 진실을 아는 사람이 있나 없나..
        bool possible=true;
        cur_present=party[i][0];
        for(int j=1; j<=t; j++){ // 진실 아는 사람들 있나 확인
            if(find_set(cur_present)==find_set(truer[j])){
                possible=false; break;
            }
        }
        if(possible) result++;
    }

    cout<<result;
}
