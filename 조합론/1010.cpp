#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t,n,m;
    cin>>t;
    vector<vector<int>>pascal(31,vector<int>(31,0));
    for(int i=0; i<=30; i++){
        pascal[i][0]=1;
    }
    for(int i=1; i<=30; i++){
        for(int j=1; j<=i; j++){
            pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
        }
    }
    while(t--){
        cin>>n>>m;
        cout<<pascal[m][n]<<'\n';
    }
}
