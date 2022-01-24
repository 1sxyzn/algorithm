#include<iostream>

using namespace std;

const int SIZE=8;
int num[SIZE];
int check[SIZE+1]; //방문한 수 인지 체크하는 배열
int n,m;

void backtracking(int index){ //index = 수열의 index
    //종료조건
    if(index==m) {
        for (int i = 0; i < index; i++)
            cout << num[i] << ' ';
        cout<<'\n';
        return;
    }
    //백트래킹
    for(int i=1; i<=n; i++){
        if(!check[i]) { //중복되는 수가 없어야 하므로 check 배열 확인
            num[index]=i; //수열에 값 저장
            check[i]=true; // 방문 확인
            backtracking(index+1); //다음 수 검사
            check[i]=false; //원래대로 돌려놓기
        }
    }
}

int main() {
    cin>>n>>m;

    backtracking(0);
}
