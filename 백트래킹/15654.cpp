#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int SIZE=8;
vector<int> num; // n의 수를 입력 받을 벡터
int number[SIZE]; //답을 저장할 배열
bool check[10001]; //방문 확인할 벡터
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
    for(int i=0; i<num.size(); i++) {
        if(!check[i]) { //중복되는 수(1 1, 2 2 등)가 없어야 하므로 check 배열 확인
            number[index]=num[i]; //수열에 값 저장
            check[i]=true; // 방문 확인
            backtracking(index+1); //다음 수 검사
            check[i]=false; //원래대로 돌려놓기
        }
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
    num.erase(unique(num.begin(),num.end()),num.end()); //중복되는 수 제거

    backtracking(0);
}
