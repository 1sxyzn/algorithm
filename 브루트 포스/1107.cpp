#include<iostream>
#include<vector>

using namespace std;

const int MAX = 1000000;

/*
 1. 현재 채널인 100번에서 하나씩 +, - 해서 원하는 채널까지 가는 횟수
 2. n =50 일 경우
    0번(=i)을 누른 후 + - 해서 50까지 가는 횟수,
    1번(=i)을 누른 후 + - 해서 50까지 가는 횟수,
    ...
    49(=i)번을 누른 후 + - 해서 50까지 가는 횟수... (이때 숫자 i에 고장난 버튼이 포함되면 건너뜀)
    ...를 다 계산해서 1번과 비교한 후, 최솟값을 택한다.
 */

int canPress(int channel, vector<bool> button){ //숫자 버튼을 눌러서 i번 채널로 갈 수 있는지, 있다면 몇 번 눌러야 하는지(=몇자리 수 채널인지) 계산
    int cnt=0;

    if(!channel) //채널이 0일 때
        return !button[0]; // 버튼이 망가지면 0, 아니면 카운트+1 반환


    while(channel) {
        if (button[channel % 10]) //버튼 하나가 부서지면 이동 불가, 0 반환
            return 0;
        channel/=10;
        cnt++;
    }
    return cnt;
}

int main() {
    int n, m, temp, i;
    vector<bool>button(10,false); //망가진 버튼은 true로
    cin>>n>>m;
    temp=m;
    while(temp--){
        cin>>i; //고장난 버튼 입력
        button[i]=true;
    }

    //1. 현재 채널인 100번에서 하나씩 +, - 해서 원하는 채널까지 가는 횟수
    int one_click=abs(n-100); //현재 채널이 100
    if(m==10){ //망가진 버튼의 갯수가 10개면 다 망가짐, + - 만 이용 가능
        cout<<one_click<<'\n'; // + - 만 이용한 값이 정답
        return 0; //프로그램 종료
    }

    int min_click=one_click;

    //2. i번을 누른 후 i번 에서 + - 해서 n까지 가는 횟수 계산...
    //      그 중 [1.] 에서 구한 값 보다 작은 값이 있을 때마다 갱신
    for(int i=0; i<MAX; i++){ // i번 채널로 가서 + -를 이용해 n으로 가는 횟수 계산
        int direct_click = canPress(i, button); // i번 채널로 갈 수 있으면, 가기 위해 숫자 버튼 누르는 횟수 계산
        if(direct_click!=0) //숫자 버튼을 눌러서 한번에 이동할 수 있으면
            min_click=min(min_click, abs(n-i) + direct_click); // 최솟값 구하기
    }
    cout<<min_click<<'\n';
}
