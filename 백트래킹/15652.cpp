#include<iostream>

using namespace std;

const int SIZE=8;
int num[SIZE];
int n,m;


void backtracking(int index, int start){
    //종료조건
    if(index==m) {
        for (int i = 0; i < index; i++)
            cout << num[i] << ' ';
        cout<<'\n';
        return;
    }
    //백트래킹
    for(int i= start; i<=n; i++){
        num[index]=i;
        backtracking(index+1, i); //15650과 비슷, 오름차순 이지만 1 1 처럼 중복가능이니 start값에 i+1이 아니라 i값 전달
    }
}

int main() {
    cin>>n>>m;

    backtracking(0, 1);
}
