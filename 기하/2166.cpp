#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n; cin>>n;
    vector<pair<long long, long long>>dot(n+1, {0,0});
    for(int i=0; i<n; i++){
        cin>>dot[i].first>>dot[i].second;
    }
    dot[n]=dot[0]; // 외적 하려면 제일 마지막에 처음 값 포함시켜야함
    double ans=0;
    for(int i=0; i<n; i++){
        ans += dot[i].first * dot[i+1].second - dot[i+1].first * dot[i].second;
    }
    cout<<fixed;
    cout.precision(1);
    cout<<abs(ans/2.0);
}
