#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
  
    int n,k;
    cin>>n>>k;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int sum=0;
    for(int i=0; i<k; i++){
        sum+=v[i];
    }
    int max=sum;
    for(int i=k; i<n; i++){
        sum-=v[i-k];
        sum+=v[i];
        if(max<sum) max=sum;
    }
    cout<<max;
}
