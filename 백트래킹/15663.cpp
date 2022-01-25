#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
 * 1 9 9 를 입력 받을 때
 * 1 9
 * 1 9 처럼 중복된 수열이 출력될 수 있다. 이를 방지하기 위해
 * 이전에 고른 (두번째 자리) 숫자, pre_num을 저장하여
 * 이전에 고른 (두번째 자리) 숫자와 같으면 연산을 건너뛰도록 한다.
 */
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

    int pre_num=-1; //이전에 고른 숫자 저장할 변수
    //백트래킹
    for(int i=0; i<num.size(); i++) {
        //if문에서 중복되는 수(1 1, 2 2 등)가 없어야 하므로 check 배열 확인 && 아까 나왔던 두번째 자리 숫자면 건너뛰기
        if(!check[i] && pre_num != num[i]) {
            number[index]=num[i]; //수열에 값 저장
            pre_num=num[i]; //직전에 고른 숫자 저장
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

    backtracking(0);
}
