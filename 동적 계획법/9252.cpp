#include<iostream>
#include<vector>

using namespace std;

string a,b;
vector<vector<int>>lcs;
vector<char>ans;

void getPath(int r, int c){
    if(r==0 || c==0) return;

    if(a[r-1]==b[c-1]){
        ans.push_back(a[r-1]);
        getPath(r-1, c-1);
    }

    else{
        if(lcs[r-1][c] > lcs[r][c-1]) getPath(r-1, c);
        else getPath(r, c-1);
    }
}

int main(){
    cin>>a>>b;
    lcs.assign(a.length()+1, vector<int>(b.length()+1, 0));

    for(int i=1; i<=a.length(); i++){
        for(int j=1; j<=b.length(); j++){
            //같은 문자면 대각선 + 1
            if(a[i-1]==b[j-1]) lcs[i][j]=lcs[i-1][j-1]+1;
            //다른 문자면 왼쪽 or 위쪽 중 큰 값
            else lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    cout<<lcs[a.length()][b.length()]<<'\n';

    getPath(a.length(), b.length());
    for(int i=ans.size()-1; i>=0; i--){
        cout<<ans[i];
    }

}
