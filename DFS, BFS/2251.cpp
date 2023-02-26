#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int capacity[3]; // A, B, C가 담을 수 있는 최대 용량 저장
bool visit[201][201]; // visit[5][2]라면 A에는 5L, B에 2L 있는 경우
bool ans[201]; // ans[4]=true 라면 C에 4L가 담기고 A에 0L가 담길 수 있다는 뜻

// 0: A, 1: B, 2: C => start[0], target[2] 인 경우는 A에서 B로 물을 이동하는 경우
int start[6]={0,0,1,1,2,2};
int target[6]={1,2,0,2,0,1};

void bfs(){
    queue<pair<int,int>>q;
    q.push({0,0}); // 초기 상태 저장
    visit[0][0]=true;
    ans[capacity[2]]=true; // 초기 상태 저장

    while(!q.empty()){
        int a=q.front().first;
        int b=q.front().second;
        int c=capacity[2]-a-b;
        q.pop();

        // 이동할 수 있는 6개 경우 완탐
        for(int i=0; i<6; i++){
            int next[3]={a,b,c};
            next[target[i]]+=next[start[i]]; // 받는 쪽으로 물 추가
            next[start[i]]=0; // 보내는 쪽 물 용량 0으로 변경

            // 받는 쪽 물이 넘칠 경우
            if(next[target[i]]>capacity[target[i]]){
                next[start[i]]=next[target[i]]-capacity[target[i]]; // 넘치는 만큼 원래 물통에 다시 넣기
                next[target[i]]=capacity[target[i]]; // 받는 물통은 꽉 채우기
            }

            // 이동 한 결과 방문 표시
            if(!visit[next[0]][next[1]]){
                visit[next[0]][next[1]]=true;
                q.push({next[0],next[1]});
                // 이동 결과가 정답인 경우 (A물통이 0L인 경우)
                if(next[0]==0) ans[next[2]]=true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>capacity[0]>>capacity[1]>>capacity[2];
    bfs();

    for(int i=0; i<=200; i++){
        if(ans[i]) cout<<i<<' ';
    }
}
