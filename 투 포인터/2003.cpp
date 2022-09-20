#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int left=0, right=0, ans=0, sum=v[left];
    while(right<n && left<=right){
        if(sum<=m || left==right) {
            if(sum==m) ans++;
            right++;
            sum+=v[right];
        }
        else{
            sum-=v[left];
            left++;
        }
    }
    cout<<ans;
}
