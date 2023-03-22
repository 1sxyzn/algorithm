#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    vector<long long>fact(21,1); // 팩토리얼 (경우의 수 담는 배열)
    vector<long long>perm(21,1); // 순열 (정답 담는 배열)
    vector<bool>used(21,false);

    for(int i=1; i<=n; i++){
        fact[i]=fact[i-1]*i; // 팩토리얼 초기화
    }

    if(q==1){ // k 번째 수열 찾기
        long long k;
        cin>>k;
        for(int i=1; i<=n; i++){
            int cnt=1;
            for(int j=1; j<=n; j++){
                if(used[j])
                    continue; // 이미 수열에 쓰인 수면 continue;

                // 4자리 수인데 k <= 3!이면 앞자리 1인거고(자리수 하나 고정)
                // k>3!이면 앞자리 2 3 4 중 하나인 거고.. 이것 판별
                if(k <= cnt * fact[n-i]){
                    // 자리수 하나 고정인 케이스 (6번째 아랫 줄 참고)

                    // (반복문 이미 거친 후 cnt++해서 cnt=2 가 된 경우)
                    // (k>3! 인 상태라 cnt++된 것이므로, 맨 앞자리 2, 3, 4 중 하나란 뜻, 그렇다면 맨 앞 자리가 1이었을 경우의 수를 빼주어야 함 그래서 k-= .. )
                    k -= (cnt-1) * fact[n-i];

                    perm[i]=j; // i 번째 자리수는 j로 고정됨

                    used[j]=true; // j는 사용됨
                    break; // 다음 자리수 (i+1) 찾으러 가기
                }
                cnt++; // 4자리 수인데 k>3!이면 맨 앞자리 다시 찾아야 함 -> for j 문 다시 반복
            }
        }
        for(int i=1; i<=n; i++){
            cout<<perm[i]<<' ';
        }
    }

    else{ // 몇 번째 수열 인지 찾기
        long long k=1; // 정답
        for(int i=1; i<=n; i++){
            cin>>perm[i];

            long long cnt=0; // 미사용 숫자 갯수 카운트
            // 예를 들어 321 앞에는 123 132 213 231, 총 4개가 있다는걸 카운트 하려면
            // 맨 앞자리 수 1, 2가 올 수 있음을 카운트하고, 뒤에 2! 경우의 수 만큼 올 수 있으니 2*2! =4, 이런식으로 카운트

            // 예를 들어 231 앞에는 123, 132, 213, 총 3개가 있다는 걸 카운트 하려면
            // 맨 앞자리 수 1이 오는 경우를 카운트하고, 뒤에 올 수 있는 가지수 2! 해서 1*2! = 2
            // 두 번째 자리 수는 3인데 앞자리 수 2이므로 올 수 있는 것 '1', 1*1! =1 해서 총 2+1=3
            for(int j=1; j<perm[i]; j++){
                if(!used[j]) cnt++;
            }
            k += cnt * fact[n-i]; // 경우의 수 누적 합
            used[perm[i]] = true; // i 자리수까지 확인 완
        }
        cout<<k;
    }
}
