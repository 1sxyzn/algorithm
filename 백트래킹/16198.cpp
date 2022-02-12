#include<iostream>
#include<vector>

using namespace std;

vector<int> w;
int ans;

void backtracking(int sum){ //backtracking 의 인자로 누적합 한 값을 보내자
    if(w.size()==2){
        ans = max(ans, sum);
        return;
    }
    for(int i=1; i<w.size()-1; i++){ //처음과 마지막 구슬은 선택하지 않는다
        int temp_w = w[i];
        int temp_sum = w[i-1] * w[i+1];
        w.erase(w.begin()+i); //방문한 구슬은 삭제한다
        backtracking(sum + temp_sum); //백트래킹 연산
        w.insert(w.begin()+i, temp_w); // 구슬 다시 원위치 시키고, 백트래킹 연산 이어서
    }
}

int main(){
    int n;
    cin>>n;
    w.assign(n,0);
    for(int i=0; i<n; i++)
        cin>>w[i];

    backtracking(0);
    cout<<ans<<'\n';
}
