#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>student(n+1, vector<int>(n+1,0)); // 모르면 0, 알면 1
    while(m--){
        int s,e;
        cin>>s>>e;
        student[s][e]=1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(student[i][k] == 1 && student[k][j] == 1) student[i][j]=1; // 누군가(k)를 거쳐서 내 키 순서를 알 수 있다면 1로 변경
            }
        }
    }

    int ans=0;
    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(student[i][j]==1 || student[j][i]==1) cnt++;
        }
        if(cnt == n-1) ans++;
    }
    cout<<ans;
}
