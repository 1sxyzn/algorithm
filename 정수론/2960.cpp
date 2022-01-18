//
// Created by user on 2022-01-19.
//
#include<iostream>
#include<vector>

using namespace std;

int is_prime(int n, int k){
    vector<bool> prime(n+1, true);
    int cnt=0;
    for(int i=2; i<=n; i++) {
        if (prime[i]) { //해당 수가 지워지지 않은 수라면
            for (int j = i; j <= n; j += i) {
                if(prime[j]){ // 그 배수 중에 지워지지 않은 배수들을 골라서
                    prime[j] = false; //지우기
                    if (++cnt == k) //k번째 지우는 수 반환
                        return j;
                }
            }
        }
    }
}

int main() {
    int n, k;
    cin>>n>>k;
    cout<<is_prime(n,k)<<'\n';
}

