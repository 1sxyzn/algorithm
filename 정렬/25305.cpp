#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,k,i;
    vector<int>v;
    cin>>n>>k;
    while(n--){
        cin>>i;
        v.push_back(i);
    }
    sort(v.begin(), v.end());
    cout<<v[v.size()-k];
}
