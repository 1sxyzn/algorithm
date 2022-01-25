#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//N과 M (7) 에서 중복되는 수 제거하는 코드 한 줄 추가

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
    for(int i=0; i<num.size(); i++) {
        number[index]=num[i];
        backtracking(index + 1);
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
    num.erase(unique(num.begin(),num.end()),num.end()); //(추가 코드) 중복되는 수 제거

    backtracking(0);
}
