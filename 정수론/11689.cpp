#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n; cin>>n;
    long long result=n;
    for(long long i=2; i*i<=n; i++){
        if(n%i==0){
            result=result-(result/i);
            // n 제곱근까지만 오일러 피 계산 하므로, n=i^j 일 경우, i 가 j 까지 안커질 수 있음 -> i로 나눠서 i^j을 j만 남기고 없애기
            while(n%i==0){
                n/=i;
            }
        }
    }
    // 20의 경우, 1 3 7 9 11 13 17 19 으로 총 8개 남아야 함,
    // i가 4까지 밖에 안커짐
    // i=2일때 result = 20 - 10 = 10, while에 의해 n=10 -> n=5
    // i가 2의 배수인건 for문에 의해 빠졌는데, 5의 배수인건 안빠짐 (애초에 5는 20의 제곱근보다 작음)
    // result=10이고 n이 5이므로 오일러피 해주자
    if(n>1) result=result-(result/n);
    cout<<result;
}
