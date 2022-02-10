#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> square;

//conquer : 모두 같은 색이라면 true 리턴
bool conquer(int size, int row, int col, int color){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(square[row+i][col+j]!=color)
                return false;
        }
    }
    return true;
}

//divide : 색종이 4 등분 내기
vector<int> divide(int size, int row, int col){
    vector<int> combine(2,0); //색종이 갯수 세서 반환

    //conquer : 모두 같은 색의 색종이라면 divide 종료
    if(conquer(size, row, col, square[row][col])){
        combine[square[row][col]]++; //같은 색이라면 색종이 +1
        return combine; //divide 종료
    }

    //같은 색의 색종이가 아니면 divide
    int sub_size = size/2;
    for(int i=0; i<=sub_size; i+=sub_size){
        for(int j=0; j<=sub_size; j+=sub_size){
            vector<int> sub_square = divide(sub_size,row+i,col+j); //나눈 후, 단색 색종이 계산한 값 저장

            combine[0] += sub_square[0];
            combine[1] += sub_square[1];
        }
    }
    return combine;
}

int main(){
    int n;
    cin>>n;
    square.assign(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin>>square[i][j];
    }

    vector<int>ans = divide(n, 0, 0);
    cout<<ans[0]<<'\n'<<ans[1]<<'\n'; //하얀색은 0, 파란색은 1
}
