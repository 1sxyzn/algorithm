#include<iostream>
#include<vector>

using namespace std;

vector<vector<char>>board;

//       오른쪽, 아래 를 의미
int r[2]={1,0};
int c[2]={0,1};

int countCandy(int n){
    int row=1, col=1; //행 연산시 최대 사탕 갯수, 열 연산시 최대 사탕 갯수
    int max_num; // 순간의 최대 사탕 갯수

    //행 검사
    for(int i=0; i<n; i++){
        max_num = 1;
        for(int j=0; j<n-1; j++){
            if(board[i][j] == board[i][j+1])
                max_num++;
            else
                max_num=1;
            row = max(row, max_num);
        }
    }

    //열 검사
    for(int i=0; i<n; i++){
        max_num = 1;
        for(int j=0; j<n-1; j++){
            if(board[j][i] == board[j+1][i])
                max_num++;
            else
                max_num=1;
            col = max(col, max_num);
        }
    }

    int ans = max(row, col);
    return ans;
}

int switchCandy(int n, int i, int j){
    int ans=0;
    //오른쪽, 아래 = 총 2번 이동
    for(int k=0; k<2; k++){
        //k가 1일땐 오른쪽 사탕과 변경, 2일땐 아래 사탕과 변경되는 것임
        //바꾸려는 사탕이 범위 내의 사탕이고, 기존의 사탕과 다를 때 변경
        if(i+r[k]<n && j+c[k]<n && board[i][j]!=board[i + r[k]][j + c[k]]) {
            swap(board[i][j], board[i + r[k]][j + c[k]]);
            ans = max(countCandy(n), ans);
            swap(board[i][j], board[i + r[k]][j + c[k]]);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    board.assign(n,vector<char>(n));

    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++)
            cin>>board[i][j];
    }

    int max_candy=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            max_candy = max(max_candy, switchCandy(n, i, j));
    }

    cout<<max_candy<<'\n';
}
