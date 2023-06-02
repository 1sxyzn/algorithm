#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n,0);
    int sum=0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(i<k) sum+=v[i];
    }
    int p1=0, p2=k-1, MAX=sum;
    while(p2<n-1){
        sum-=v[p1];
        p1++;
        p2++;
        sum+=v[p2];
        MAX=max(MAX, sum);
    }
    cout<<MAX;
}
