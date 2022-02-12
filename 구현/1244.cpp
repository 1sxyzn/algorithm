#include<iostream>
#include<vector>

using namespace std;

vector<int>switches;
int n;

void boy(int b){
    for(int i=b; i<=n; i+=b)
        switches[i] = !switches[i]; //스위치 상태 변경
    return;
}

void girl(int b){
    int i=1;
    switches[b] =!switches[b]; //자기 자신의 것 먼저 바꾸기
    while( (b-i)>0 && (b+i)<n+1){ //범위 벗어나면 반복 종료
        if(switches[b-i]!=switches[b+i])
            return;
        else{
            switches[b-i] =!switches[b-i];
            switches[b+i] =!switches[b+i];
        }
        i++;
    }
    return;
}

int main(){
    cin>>n;
    switches.assign(n+1,0);
    for(int i=1; i<=n; i++)
        cin>>switches[i];

    int total;
    int a, b;
    cin>>total;

    for(int i=0; i<total; i++){
        cin>>a>>b;
        if(a==1) boy(b);
        else if(a==2) girl(b);
    }

        for(int i=1; i<=n; i++){
            cout<<switches[i]<<' ';
            if(i%20==0) //한 줄에 20개씩만 출력하기
                cout<<'\n';
        }
}
