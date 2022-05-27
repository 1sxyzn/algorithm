#include<iostream>
#include<vector>

using namespace std;

// 도시까지의 거리는 1이상 1,000,000,000 이하의 자연수
// 리터당 가격은 1 이상 1,000,000,000 이하의 자연수 이므로
// int가 아닌 long long 으로 선언

long long greedy(vector<long long> road, vector<long long> oil, int n){
    long long ans = 0;
    long long cost = oil[0]; //가능한 최소 기름의 가격
    ans += cost * road[0];
    for(int i=1; i<n-1; i++){
        if(cost > oil[i]){ //다음 주유소의 기름 가격이 더 낮다면
            cost = oil[i]; //다음 주유소에서 충전
        }
        ans += cost * road[i]; //다음 주유소의 가격이 더 비싸면 기존 주유소에서 미리 충전해왔다고 생각
    }

    return ans;
}

int main(){
    int n; //도시 수
    cin>>n;
    vector<long long> road(n-1); //도로 거리, 이만큼의 기름이 필요
    vector<long long> oil(n); //기름의 가격

    for(int i=0; i<n-1; i++){
        cin>>road[i];
    }
    for(int i=0; i<n; i++){
        cin>>oil[i];
    }
    cout<<greedy(road, oil, n);
}
