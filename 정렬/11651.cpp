#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int,int>a, pair<int,int>b){
    if(a.second==b.second) return a.first<b.first;
    else return a.second<b.second;
}

int main(){
    int n, x, y;
    vector<pair<int,int>>v;
    cin>>n;
    while(n--){
        cin>>x>>y;
        v.emplace_back(x,y); //임시 객체 만들지 않고 push하려면 push가 아닌 emplace
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++){
        cout<<v[i].first<<' '<< v[i].second<<'\n';
    }
}
