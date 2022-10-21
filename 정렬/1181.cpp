#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    if(a.length()!=b.length())
        return a.length()<b.length();
    else
        return a<b;
}

int main(){
    int n;
    cin>>n;
    string s;
    vector<string>v;
    while(n--){
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),cmp);
    cout<<v[0]<<'\n';
    for(int i=1; i<v.size(); i++){
        if(v[i]!=v[i-1])
            cout<<v[i]<<'\n';
    }
}
