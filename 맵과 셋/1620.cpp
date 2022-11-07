#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n;
    cin>>m;
    map<string,int> searchName;
    vector<string> searchNum(n+1);
    string s;

    for(int i=1; i<=n; i++){
        cin>>s;
        searchName[s]=i;
        searchNum[i]=s;
    }

    while(m--){
        cin>>s;
        if(s[0]>='0' && s[0]<='9') cout<<searchNum[stoi(s)]<<'\n';
        else cout<<searchName[s]<<'\n';
    }
}
