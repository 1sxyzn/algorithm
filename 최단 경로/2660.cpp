#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>>v(n+1,vector<int>(n+1,987654321));
    for(int i=0; i<=n; i++) v[i][i]=0;

    int a=0, b=0;
    while(true){
        cin>>a>>b;
        if(a==-1 && b==-1) break;
        v[a][b]=1;
        v[b][a]=1;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(v[i][j] > v[i][k] + v[k][j]) v[i][j] = v[i][k] + v[k][j];
            }
        }
    }

    int MIN = 987654321;
    vector<int>score(n+1,0); // 회장 후보들의 점수를 저장
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j) score[i] = max(v[i][j], score[i]); // 가장 큰 값이 점수
        }
        MIN = min(score[i], MIN); // 회장 후보들의 점수 중 가장 작은 값 찾기
    }

    vector<int>ans;
    for(int i=1; i<=n; i++){
        if(score[i] == MIN) {
            ans.push_back(i);
        }
    }
    cout<<MIN<<' '<<ans.size()<<'\n';
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<' ';
}
