#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>>winner(n+1,vector<bool>(n+1,false));
    for(int i=0; i<results.size(); i++){
        winner[results[i][0]][results[i][1]]=true;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(winner[i][k] && winner[k][j]) winner[i][j]=true;
            }
        }
    }

    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++) if(winner[i][j]!=0 || winner[j][i]) cnt++;
        if(cnt==n-1) answer+=1;
    }

    return answer;
}
