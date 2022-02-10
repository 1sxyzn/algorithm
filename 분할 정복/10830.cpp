#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> mat;

//combine : 행렬 곱한 결과 리턴
vector<vector<int>> combine(int n, vector<vector<int>> row_vec, vector<vector<int>> col_vec){
    vector<vector<int>> mul(n,vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++)
                mul[i][j] += row_vec[i][k] * col_vec[k][j];
            mul[i][j]%=1000;
        }
    }
    return mul;
}

//divide : 짝수, 홀수 제곱으로 나눠서 계산
vector<vector<int>> divide(int n, long long b){
    if(b==1) //기저조건
        return mat;

    if(b%2==0){ //짝수일 경우
        vector<vector<int>> sub_mat = divide(n, b/2);
        return combine(n, sub_mat, sub_mat);
    }

    //홀수일 경우
    return combine(n, mat, divide(n, b-1));

}

int main(){
    int n;
    long long b;
    cin>>n>>b;
    mat.assign(n,vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }
    vector<vector<int>> ans = divide(n,b);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ans[i][j] % 1000 <<' ';
            //원소가 다 1000이고, b=1 인 경우에는 원소가 1000인채로 출력됨 => %1000 해주기
        }
        cout<<'\n';
    }
}
