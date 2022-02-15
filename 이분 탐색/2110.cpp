// 매개 변수 탐색, 효율성 문제에서 많이 나옴!

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> house;

// 공유기 c개를 설치할 때 집 사이의 거리를 최대로 하고자하는 문제
// 반대로 생각해서, 거리를 1로 했을 때 c개를 설치할 수 있나? 거리를 2로 했을 때 c개를.... 이런식으로 생각
// 만약 c개를 설치할 수 있는 거리가 여러 개라면 그 중 가장 큰 거리를 택하면 정답!!

// 거리를 dist로 했을 때 몇개의 공유기를 설치할 수 있는지 계산
int router(int dist){
    int cnt = 1; // 공유기 설치한 갯수
    int pos = house[0]; //마지막에 설치한 집

    for(int i=1; i<house.size(); i++){
        if(house[i]-pos < dist) //설치해야하는 거리보다 짧으면 설치 못함
            continue;
        cnt++; //설치해야하는 거리보다 멀면 설치 가능
        pos = house[i]; // 마지막에 설치한 집 갱신
    }
    return cnt;
}

// router_num 만큼의 공유기를 설치할 때,
// 설치 가능한 집 사이의 거리가 여러 가지 경우 라면 그 중 최대 거리 택하기
int upperSearch(int left, int right, int router_num){
    int ans=0;
    while(left<=right){
        int mid = (left+right)/2;
        int installed = router(mid); //install은 거리가 mid일 때 설치할 수 있는 공유기 갯수

        if(installed<router_num) //설치해야하는 공유기가 더 있으면? 거리를 줄여서 더 많이 설치하자
            right = mid -1;
        else { // 더 적은 공유기를 설치해야할 때 or 딱 맞게 설치할 때(=> 깉은 갯수의 공유기를 더 먼 간격으로 설치할 수 있나 확인!)
            ans = mid;
            left = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n, c;
    cin>>n>>c; //집의 갯수, 공유기의 갯수
    house.assign(n,0);
    for(int i=0; i<n; i++)
        cin>>house[i];
    sort(house.begin(), house.end());

    //매개변수는 공유기 사이의 거리
    // 최소 : 1
    // 최대 : 가장 먼 두 집 사이의 거리)
    cout<<upperSearch(1, house[n-1]-house[0], c)<<'\n';
}
