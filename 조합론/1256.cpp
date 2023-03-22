#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<long long>>pascal(201,vector<long long>(201,0)); // n+m C n 까지 가므로 n+m의 최댓 값 200까지 저장..
    for(int i=0; i<=200; i++){
        pascal[i][0]=1;
    }
    for(int i=1; i<=200; i++){
        for(int j=1; j<=i; j++){
            pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
            if(pascal[i][j]>1000000000) pascal[i][j]=1000000001;
        }
    }
    if(pascal[n+m][n]<k) cout<<-1; // 사전에 수록되어 있는 문자열의 개수가 K보다 작은 경우
    else{
        while(n!=0 || m!=0){
            // a 2개 z 2개인 경우, a가 맨앞에 온다면 나머지 3개는 (3자리에서 aaz를 배치할 조합)만큼의 경우의 수가 생김
            // 그런데 k가 위 경우의 수보다 작으면? a 가 맨 앞인 것이 확정
            // 만약 k가 위 경우의 수보다 크면? 맨 앞은 z로 시작됨
            if(pascal[n-1 + m][m] >= k){
                cout<<"a";
                n--; // a 한 개 썼으므로 a 갯수 --
            }
            else {
                cout<<"z";
                k -= pascal[n-1 + m][m]; // a가 맨 앞에 오지 않는 다는 것이 확정났다면 -> 전체 경우의 수에서 그만큼 빼줘야 함
                m--;
            }
        }
    }
}
