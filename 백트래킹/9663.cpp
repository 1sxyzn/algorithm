#include<iostream>

using namespace std;

const int SIZE =15;
int n,ans=0;

bool check_col[SIZE]; //열 체크
bool check_left[SIZE*2]; //우하향 대각선 체크, i+j를 인덱스로 가짐
bool check_right[SIZE*2]; //좌하향 대각선 체크, i-j+n을 인덱스로 가짐

/*
 * 이차원 배열로 하면 시간초과.
 * 각 줄을 인덱스로 생각하고 일차원 배열로 접근!!
 * 인덱스의 경우, 우하향 대각선 = i+j (i는 행, j는 열)
 * 좌하향 대각선 = i-j +n (i-j는 음수이므로 +n)
 */

void backtracking(int cnt) { // cnt = 행
    //종료 조건 (한 행에 퀸이 하나씩 놓여야 n*n 체스판에서 총 n개의 퀸이 놓일 수 있음)
    if(cnt == n){ //n개의 퀸이 모두 놓임
        ans++;
        return;
    }

    for(int i=0; i<n; i++){ //i = 열, 해당 cnt 행 중에 가능한 i 열을 찾자!
        if(!check_col[i] && !check_left[cnt + i] && !check_right[cnt - i + n]){
            //퀸을 놓을 수 있다면 놓기
            check_col[i] = true;
            check_left[cnt + i] = true;
            check_right[cnt - i + n] = true;
            backtracking(cnt + 1); //다음 행 연산
            //재탐색을 위해 원래 상태로 돌려 놓기
            check_col[i] = false;
            check_left[cnt + i] = false;
            check_right[cnt - i + n] = false;
        }
    }

}

int main() {
    cin>>n;
    backtracking(0);
    cout<<ans<<'\n';
}
