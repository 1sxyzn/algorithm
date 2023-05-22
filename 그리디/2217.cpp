#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end(), greater<>());
    int max_w=0;
    for(int i=0; i<n; i++){
        max_w = max(max_w, v[i] * (i+1));
    }
    cout<<max_w;
}
