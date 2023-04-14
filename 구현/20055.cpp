#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,bool>>belt; // 내구도 & 로봇 존재 여부
int zero=0;
int n,k;

int moveBelt(int x){ // 벨트가 돌아간다..
    x--;
    if(x>=0) return x; // 벨트 위 로봇을 움직이기 힘드니 내리고 올리는 위치를 변화시키자..
    else return 2*n-1;
}

void moveRobot(int s, int e){ // 로봇이 돌아간다..
    // 가장 먼저 벨트에 들어간 로봇은? 내리는 칸에 가장 가까운 로봇..
    int check = e;
    while(check!=s){ // 내리는 칸 -> 올리는 칸 순서로 로봇 이동 가능한지 체크
        check = moveBelt(check);
        int next = (check+1) % (2*n);
        if(belt[check].second && !belt[next].second && belt[next].first>0){
            belt[check].second = false;
            belt[next].first--;
            if(next!=e) belt[next].second = true; // 내리는 칸이 아니면 로봇 옮기기.. 내리는 칸이면.. 옮기지 말고 내리기만 해야함..
            if(belt[next].first==0) zero++;
        }
    }
}

void upRobot(int s){ // 로봇을 올린다..
    if(belt[s].first>0){
        belt[s].second=true; // 벨트 올리기
        belt[s].first--;
        if(belt[s].first==0) zero++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;

    belt.assign(2*n,{0,false});
    for(int i=0; i<2*n; i++){
        cin>>belt[i].first; // 내구도 저장
    }

    int s=0, e=n-1, step=0; // 로봇 올리는 위치, 내리는 위치, 단계
    while(true){
        s = moveBelt(s);
        e = moveBelt(e);

        if(belt[e].second){ // 벨트 돌아갔는데 로봇이 내리는 위치에 있다면
            belt[e].second=false;
        }
        // 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
        moveRobot(s,e);

        // 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
        upRobot(s);

        step++;
        if(zero>=k) break;
    }
    cout<<step;
}
