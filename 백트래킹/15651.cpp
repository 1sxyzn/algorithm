#include<iostream>

using namespace std;

const int SIZE=8;
int num[SIZE];
int n,m;

void backtracking(int index){
    //종료조건
    if(index==m) {
        for (int i = 0; i < index; i++)
            cout << num[i] << ' ';
        cout<<'\n';
        return;
    }
    //백트래킹
    for(int i=1; i<=n; i++){
        num[index]=i; //수열에 값 저장
        backtracking(index+1); //다음 수 검사
        }
    }

int main() {
    cin>>n>>m;

    backtracking(0);
}
