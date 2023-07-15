#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string add (string a, string b){
    int sum = 0;
    string res;

    while(!a.empty() || !b.empty() || sum>0){
        if(!a.empty()){
            sum += (a.back() - '0');
            a.pop_back();
        }
        if(!b.empty()){
            sum += (b.back() - '0');
            b.pop_back();
        }
        res.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<string>>pascal(n+1, vector<string>(n+1,"0"));

    for(int i=0; i<=n; i++) pascal[i][0]='1';

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            pascal[i][j] = add(pascal[i-1][j], pascal[i-1][j-1]);
        }
    }

    cout<<pascal[n][m];
}
