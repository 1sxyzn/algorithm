#include<iostream>
#include<vector>

using namespace std;

//에라토스테네스의 체를 이용해서 소수가 아닌건 false로, 소수인 것은 true로
vector<bool> isPrime(int n){
    vector<bool>is_prime(n+1, true);
    is_prime[0]=is_prime[1]=false;// 0과 1은 소수가 아님
    for(int i=2; i*i<=n; i++){ //n의 제곱근까지만 검사
        if(is_prime[i]){ //소수이면 배수들을 false로 변경
            for(int j=i*i; j<=n; j+=i) //i의 제곱 이후로 검사
                is_prime[j]=false;
        }
    }
    return is_prime;
}

// 소수인 것을 골라 벡터에 담기
vector<int> Prime(vector<bool> is_prime){
    vector<int>prime;
    for(int i=2; i<= is_prime.size(); i++){
        if(is_prime[i])
            prime.push_back(i);
    }
    return prime;
}

// n을 소수의 합으로 나타낼 수 있는 경우의 수 계산
//left와 right는 같은 방향으로 증가
int sumCount(vector<int> prime, int n){
    int count=0;
    int left=0, right=0;

    //만약 소수가 없으면 0 리턴. (n은 1부터 입력 가능한데 n=1일 경우 소수가 없음, n=2일 경우 자기자신은 소수)
    if(prime.size()==0)
        return 0;

    int sum = prime[left]; //소수들의 합 저장, 초기값은 prime[left]

    while(left<=right && right<prime.size()){
        if(sum > n){ //n을 만들어야하는데 현재 n보다 크면 값을 줄이기위해 작은 값 가리키는 left 이동
            sum-=prime[left]; //현재 합에서 가장 왼쪽에 있는 값을 빼고
            left++; //포인터 이동
        }
        else{ //만들어야하는 n과 같거나 n보다 작을 때
            if(sum == n)
                count++; //경우의 수 증가
            right++; //포인터 이동
            if(right==prime.size()) //포인터 이동했는데 그게 범위 밖이면
                break; //반복문 종료
            sum+=prime[right]; //이동했다면, 이동한 포인터에 위치한 값 저장
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;

    vector<bool> is_prime = isPrime(n); //소수가 아닌 것은 false로 처리
    vector<int> prime = Prime(is_prime); //소수만 벡터에 담기
    int ans = sumCount(prime, n); // n을 소수의 합으로 나타낼 수 있는 경우의 수 계산

    cout<<ans<<'\n';
}
