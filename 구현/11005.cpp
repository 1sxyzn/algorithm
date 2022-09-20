#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n, b;
    cin>>n>>b;
    vector<int>v;
    while(n){
        v.push_back(n%b);
        n/=b;
    }
    for(int i=v.size()-1; i>=0; i--){
        if(v[i]>=10){
            v[i]-=10;
            cout<<char('A'+v[i]);
        }
        else cout<<v[i];
    }
}
