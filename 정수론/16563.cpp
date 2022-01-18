#include<iostream>
#include<vector>

using namespace std;

const int SIZE = 5000000;

vector<int> is_prime(){
    vector<int> prime(SIZE+1,0);
    int i,j;

    //각 수의 모든 소인수를 자기 자신으로 초기화
    for(i=2;i<SIZE+1;i++)
        prime[i]=i;

    //에라토스테네스의 체 이용
    for(i=2; i*i<SIZE+1; i++){ // i <= 루트 SIZE 까지 라고 해도 ok
         if(prime[i]==i){ //소수의 배수를 지울 것임. 소수인 것 고르기
             for(j=i*i; j<SIZE+1; j+=i){ //i*i인 이유 =
                 // 50의 경우, 50*1 ~ 50*49는
                 // 1의 배수 ~ 49의 배수를 지웠을 때 이미 지워짐
                 //그러므로 50*50 부터 50*51 순으로 확인함
                 if(prime[j]==j){ //소수가 자기 자신인 경우, 즉 지워지지 않은 수들
                     prime[j]=i;
                 }
             }
         }
    }
    return prime ;
}

int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n;

    //모든 수 마다 최소 소수를 저장
    vector<int> prime = is_prime();

    while(n--){
        cin>>k;
        while(k>1){ //소인수 계속 출력
            cout<<prime[k]<<' '; // 예를 들어 4의 경우 소인수 2가 출력됨
            k/=prime[k]; // k = 4나누기 (소인수)2 = 2가 됨.
            // while 한 번 더 돌고 k = 2가 출력 되고 K=1이 되고 while 종료
            //최종적으로 4의 경우, 2 2 가 출력됨
        }
        cout<<'\n';
    }
}
