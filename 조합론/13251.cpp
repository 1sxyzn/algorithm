#include<iostream>
#include<vector>

using namespace std;

int main(){
    int m, k;
    cin>>m;
    //파스칼 삼각형 쓰면 2500Cn 과 같은 수에서 long long의 범위르 넘어설 수 있음..
    vector<int>stone(m,0);
    int total=0;
    for(int i=0; i<m; i++){
        cin>>stone[i];
        total += stone[i];
    }
    cin>>k;
    // 특정 색깔의 돌 수Ck / 전체 돌 수Ck 를 다 더하는게 정답인데
    // 분모의 k*(k-1)* ... 는 공통이므로 생략 가능
    double ans=0;
    vector<double>prob(m,1);
    for(int i=0; i<m; i++){
        if(stone[i]>=k){ // k 보다 돌 수가 적으면 원하는 조건 성립 x
            for(int j=0; j<k; j++){
                prob[i] *= (double)(stone[i]-j)/(total-j);
            }
            ans+=prob[i];
        }
    }
    cout<<fixed;
    cout.precision(10);
    cout<<ans;
}
