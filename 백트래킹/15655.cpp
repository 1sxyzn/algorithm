#include<iostream>
#include<vector>
#include<algorithm>

//N과 M (2) 처럼 start 변수를 하나 더 받아주고, 입력을 다른 벡터에 받으면 된다

using namespace std;

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
    //백트래킹
    for(int i=start; i<num.size(); i++) {
            number[index]=num[i]; //수열에 값 저장
            backtracking(index+1, i+1); //다음 수 검사
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

    backtracking(0, 0);
    //N과 M(2)에서는 수열(num)의 index를 1부터 보냈지만, 이 문제에서는 수열(number)의 index를 0부터 함
}
