#include<iostream>
#include<vector>

using namespace std;

int main(){
    // 수를 정렬하고 합이 n인 것을 고르라고 하면 -> 보통 양 끝단에서 포인터 시작
    // 정렬되지 않은 수에서 연속된 수의 합이 n인 것을 고르라고 하면 -> 보통 같은 포인터에서 시작
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,s,ans=100000;
    cin>>n>>s;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int p1=0, p2=0;
    int sum=v[p1];
    int len; // 부분 길이
    while(p2<n && p1<=p2){
        if(sum>=s){
            len=p2-p1+1;
            if(len<ans) ans=len;
            sum-=v[p1++];
        }
        else{
            sum+=v[++p2];
        }
    }
    if(ans==100000) cout<<'0';
    else cout<<ans;
}
