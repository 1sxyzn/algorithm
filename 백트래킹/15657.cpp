#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// N과 M (4) 와 유사

const int SIZE=8;
vector<int> num; // n의 수를 입력 받을 벡터
int number[SIZE]; //답을 저장할 배열
bool check[10001]; //방문 확인할 벡터
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
            backtracking(index+1, i); //다음 수 검사
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

    backtracking(0, 0);
}
