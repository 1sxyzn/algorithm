#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>graph;
vector<int> check; //방문 체크
bool is_tree;

void dfs(int i, int parent){
    if(check[i]){ //dfs돌다가 방문한 노드 나오면 사이클 발생한 것
        is_tree=false; //트리 자격 박탈
        return; //재귀 종료
    }

    check[i]=true;
    for(int j=0; j<graph[i].size(); j++){ //i가 가진 모든 자식 노드 탐색
        //현재 i의 자식들이 j인데
        // (첫 정점 탐색시 parent가 -1인데, 그 경우 제외하고) parent와 i가 연결이 되어있으니 j에 parent가 포함됨.
        // parent를 제외한 j들을 탐색해야함
        if(graph[i][j]!=parent)
            dfs(graph[i][j],i);
    }
}

//결과 출력
//Case 1: A forest of 3 trees.
//Case 2: There is one tree.
//Case 3: No trees.
void print_result(int case_num, int tree_num){
    cout<<"Case "<<case_num<<": ";
    if(tree_num==0)
        cout<<"No trees.";
    else if(tree_num==1)
        cout<<"There is one tree.";
    else
        cout<<"A forest of "<<tree_num<<" trees.";
    cout<<'\n';
}

int main(){
    int n,m,a,b;
    int case_num=0;
    while(true){
        case_num++;
        cin>>n>>m;
        //0 0 들어오면 종료
        if(n==0 && m==0)
            break;

        graph.assign(n+1,vector<int>(0));
        check.assign(n+1, false);
        while(m--){
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int tree_num = 0;
        for(int i=1; i<=n; i++){ //트리 정점은 1부터 시작
            if(!check[i]){
                is_tree=true;
                dfs(i,-1);
                if(is_tree) //dfs한 결과 tree가 맞다면
                    tree_num++; //트리 갯수 추가
            }
        }

        print_result(case_num, tree_num);
    }
}
