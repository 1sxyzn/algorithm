#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, ans=0;
    cin>>n;
    vector<vector<bool>>board(100,vector<bool>(100));
    while(n--){
        int x,y;
        cin>>x>>y;
        for(int i=x; i<x+10; i++){
            for(int j=y; j<y+10; j++) {
                if (!board[i][j]) {
                    ans++;
                    board[i][j] = true;
                }
            }
        }
    }
    cout<<ans;
}
