#include<iostream>
#include<vector>
#include<algorithm>

//N과 M (3) 과 유사

using namespace std;

const int SIZE=8;
vector<int> num; // n의 수를 입력 받을 벡터
int number[SIZE]; //답을 저장할 배열
int n,m;

void backtracking(int index){
    //종료조건
    if(index==m) {
        for (int i = 0; i < index; i++)
            cout << number[i] << ' ';
        cout<<'\n';
        return;
    }
    //백트래킹
    for(int i= 0; i<num.size(); i++) {
        number[index]=num[i]; //수열에 값 저장
        backtracking(index+1); //다음 수 검사
    }
}

int main() {
    cin>>n>>m;
    int temp = n;
    int i;
    while(temp--){
        cin>>i;
        num.push_back(i);
    }
    sort(num.begin(), num.end()); //오름차순 정렬

    backtracking(0);
}
