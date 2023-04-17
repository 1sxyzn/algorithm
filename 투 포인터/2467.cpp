#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int l = 0, r = n-1;
    int ans1 = v[l], ans2 = v[r];
    int ans = 2e9;
    while(l<r){
        if(abs(ans) > abs(v[l]+v[r])){
            ans1 = v[l]; ans2 = v[r];
            ans = ans1 + ans2;
        }
        if(v[l]+v[r]<0) l++;
        else if(v[l]+v[r]>0) r--;
        else break;
    }
    cout<<ans1<<' '<<ans2;
}
