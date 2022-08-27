#include<iostream>
#include<vector>

using namespace std;

void fillStar(vector<vector<char>> &star, int len, int r, int c){
    if(len==1){
        star[r][c]='*';
        return;
    }
    fillStar(star, len-4, r+2, c+2);
    for(int i=r; i<r+len; i++){
        star[r][i] = '*'; // 사각형의 윗변
        star[r+len-1][i] = '*'; // 아랫변
        star[i][c] = '*'; // 좌변
        star[i][c+len-1] = '*'; // 우변
    }

}

int main(){
    int n;
    cin>>n;
    // 정사각형 한 변의 길이는 (n-1)*4+1 = 4n-3
    int len = 4*n-3;
    vector<vector<char>> star(len, vector<char>(len, ' '));

    fillStar(star, len, 0, 0);

    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            cout<<star[i][j];
        }
        cout<<'\n';
    }
}
