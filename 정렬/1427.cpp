#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int>v;
    for(int i=0; i<s.length(); i++){
        v.push_back(int(s[i]-'0'));
    }
    sort(v.begin(), v.end(), greater<>());
    for(int j=0; j<v.size(); j++){
        cout<<v[j];
    }
}
