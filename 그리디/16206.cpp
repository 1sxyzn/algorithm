#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(int a, int b){
    //둘 다 10의 배수 롤케이크 일 때,
    // 40 롤케이크는 3번 자르면 4개가 나오지만, 50 롤케이크는 3번 자르면 3개 나옴
    // => 10의 배수 중 짧은걸 먼저 자르자
    if(a%10 == 0 && b%10 == 0)
        return a<b;
    // 둘 중 10으로 나누어 떨어지는 것을 먼저 정렬하겠다는 의미! wow
    return a%10 == 0;
    // 10으로 나누어 떨어지지 않으면 순서 상관 X
}

int greedy(vector<int> cake, int n, int m){
    int ans=0;

    for(int i=0; i<n; i++){
        int cut = cake[i]/10; //25 롤케이크의 경우 2번 잘라야 10 10 (+a) 2개 나옴
        if(cake[i]%10 == 0) //30 롤케이크의 경우 2번만에 자를 수 있고,3개 나옴
            cut--; // 한번 덜 잘라도 되니 -1

        // 빵 갯수 카운트
        if(cut<=m){ // 빵 하나를 전부 자를 수 있는 경우
            m = m - cut; //자를 수 있는 횟수 감소
            ans = ans + cake[i]/10 ; //정답에 길이 10짜리 롤케이크 갯수 더해주기
        }
        else { //자를 수 있는 횟수가 적어서 하나를 다 못자른 경우
            //덜 잘랐으니, 자른 만큼만 길이 10짜리 롤케이크가 나온다... 40짜리가 10 10 20 이렇게 된경우 (= ans + 2)
            ans = ans + m; //최대 자를 수 있는 횟수만큼만 더 자르고, 자르기 종료
            break;
        }
    }
    return ans;
}

int main(){
    int n, m; //빵 갯수, 자르는 횟수
    cin >> n >> m ;
    vector<int> cake(n);
    for(int i=0; i<n; i++)
        cin>>cake[i];
    sort(cake.begin(), cake.end(), cmp);
    cout<<greedy(cake, n, m)<<'\n';
}
