#include<iostream>
#include<vector>

using namespace std;

int greedy(vector<int> coin, int n, int k){
    int count=0;

    for(int i=n-1; i>=0 ; i--){
        if(k==0) //가치합 만큼 동전을 다 쓰면 반복 종료
            break;
        if(coin[i]<=k){ //채워야하는 가치합보다 작거나 같은 가치의 동전 사용
            count +=(k/coin[i]); //큰 동전으로 우선 채우기
            k%=coin[i]; //큰 동전으로 채우고 남은 잔돈
        }
    }
    return count;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> coin;
    int i, temp=n; //임시변수
    while(temp--){
        cin>>i;
        coin.push_back(i);
    }
    cout << greedy(coin, n, k) << '\n';
}
