#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,l,sum=0,ans=0;
    cin>>n>>l;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(i<l) {
            sum+=v[i];
            if(sum<=138 && sum>=129) ans++; // 처음 l 범위 안에서 알코올 농도를 지킬 수 있음
        }
    }
    int p1=0, p2=l-1;
    while(true){
        p1++;
        p2++;
        if(p2==n) break;
        sum-=v[p1-1];
        sum+=v[p2];
        if(sum<=138 && sum>=129) ans++;
    }
    cout<<ans;
}
