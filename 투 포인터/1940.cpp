#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,m, ans=0;
    cin>>n>>m;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int p1=0, p2=n-1; // p1 p2 둘 다 증가시키는 방향으로 하면 p1가 p2를 추월하는 등의 경우 발생, 둘 다 양 끝단에서 시작하자
    while(p1<p2){
        if(v[p1]+v[p2]==m){
            ans++;
            p1++; p2--;
        }
        else if(v[p1]+v[p2]<m) p1++;
        else p2--;
    }
    cout<<ans;
}
