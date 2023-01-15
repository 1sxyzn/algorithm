#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m,k;
    cin>>n>>m;
    vector<vector<int>>v(n+1,vector<int>(n+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>k;
            v[i][j]=v[i][j-1]+v[i-1][j]-v[i-1][j-1]+k; // 합 저장
        }
    }
    while(m--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<v[x2][y2]-v[x1-1][y2]-v[x2][y1-1]+v[x1-1][y1-1]<<'\n';
    }
}
