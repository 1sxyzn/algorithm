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
 *
 * 비내림차순이므로 check 배열이 필요가 없다. 오름차순일 때도 check 배열이 필요 없다.
 * 백트래킹 함수 두번째 인자를 i+1 로 하면 한 수열에서 같은 수가 중복되지 않는다.
 * (ㄴ예시 : 1 7 9 9 를 주었을 때 9 9 는 가능하지만 1 1 은 불가능)
 * 백트래킹 함수 두번째 인자를 i로 하면 두 수가 중복 (1 1, 7 7등) 될 수 있다.
 */

const int SIZE=8;
vector<int> num; // n의 수를 입력 받을 벡터
int number[SIZE]; //답을 저장할 배열
int n,m;

void backtracking(int index, int start){
    //종료조건
    if(index==m) {
        for (int i = 0; i < index; i++)
            cout << number[i] << ' ';
        cout<<'\n';
        return;
    }

    int pre_num=-1; //이전에 고른 숫자 저장할 변수
    //백트래킹
    for(int i=start; i<num.size(); i++) {
        //아까 나왔던 두번째 자리 숫자면 건너뛰기
        if(pre_num != num[i]) {
            number[index]=num[i]; //수열에 값 저장
            pre_num=num[i]; //직전에 고른 숫자 저장
            backtracking(index+1, i+1); //다음 수 검사, 비내림차순
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
    sort(num.begin(), num.end()); //비내림차순 정렬

    backtracking(0,0);
}
