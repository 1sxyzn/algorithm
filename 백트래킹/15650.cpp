#include<iostream>

using namespace std;

const int SIZE=8;
int num[SIZE];
int n,m;


// 체크 배열이 필요 없다. why? 오름차순이므로 중복될 일이 없다

void backtracking(int index, int start){ //index = 수열의 index, start = 오름차순을 위한 시작 index
    //종료조건
    if(index==m) {
        for (int i = 0; i < index; i++)
            cout << num[i] << ' ';
        cout<<'\n';
        return;
    }
    //백트래킹
    for(int i= start; i<=n; i++){
        num[index]=i; //수열에 값 저장
        backtracking(index+1, i+1); //다음 수열 index에 담을 것 연산 & 오름차순 이므로 다음 수 (i+1) 전달
    }
}

int main() {
    cin>>n>>m;

    backtracking(0, 1);
}
