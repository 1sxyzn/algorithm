#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>v(n, {0,0});
    for(int i=0; i<n; i++){
        cin>>v[i].first;
        v[i].second=i;
    }

    sort(v.begin(), v.end()); // n * log n

    // 얼마나 버블이 많이 일어났냐 + 1 을 구하기 => 버블 시 왼쪽으로는 1칸씩만 이동함, 고로 가장 왼쪽으로 간 것이 정답
    // == 기존 인덱스 - 새 인덱스의 값이 최대인 것
    int max=-1;
    for(int i=0; i<n; i++){
        if(v[i].second - i > max) max = v[i].second-i;
    }
    cout<<max+1;
}
