#include<iostream>
#include<vector>

using namespace std;

const int SIZE =64;

//체스판에서 바꿔야하는 최소값 계산
int change(int row, int col, vector<vector<char>> board){
    int b=0; //b 시작하는 체스판을 만들기 위해 바꿔야 하는 수

    for(int i=0; i<8; i++){ //기존 row + i를 8칸 할 것임
        for(int j=0; j<8; j++){ //기존 col + i를 8칸 할 것임
            //b로 시작하는 체스판의 경우 = i+j가 짝수면 b, 홀수면 w가 됨
            if((i+j)%2==0 && board[row+i][col+j]!='B') //이 자리에 B가 아니라면 W로 바꾸고 카운트 +1
                b++;
            if((i+j)%2!=0 && board[row+i][col+j]!='W') //이 자리에 W가 아니라면 B로 바꾸고 카운트 +1
                b++;
        }
    }
    //b로 시작하는 체스판에서 바꿔야하는 수 = 8*8 - w로 시작하는 체스판에서 바꿔야하는 수
    // 둘 중 최솟값을 가져가면 됨
    if(b > SIZE/2) //b로 시작하는 체스판의 수가 더 많다면
        return SIZE-b; //w로 시작하는 체스판의 수 리턴
    return b;
}

int main () {
    int n,m,i,j;
    int ans = SIZE+1; //바꿔야하는 체스판 갯수의 최소값 저장할 변수
    cin>>n>>m;

    vector<vector<char>> board (n, vector<char>(m)); //n * m 크기의 체스판
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin>>board[i][j]; //입력


    for(i=0; i<=n-8; i++){ //시작 row
        for(j=0; j<=m-8; j++){ //시작 col
            int temp=change(i,j,board); //해당 체스판에서 바꿔야하는 수 계산
            ans=min(ans, temp); //기존의 바꿔야하는 수와, 새로 계산한 바꿔야하는 수의 최소값
        }
    }
    cout<<ans<<'\n';
}
