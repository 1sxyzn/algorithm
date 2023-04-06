#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin>>s;
    vector<vector<int>>al(26,vector<int>(s.length(),0));
    int n; cin>>n;
    for(int i=0; i<s.length(); i++){
        for(int j=0; j<26; j++){
            al[j][i] = al[j][i-1];
        }
        al[s[i]-'a'][i]++;
    }

    char c; int a,b;
    while(n--){
        cin>>c>>a>>b;
        cout<<al[c-'a'][b] - al[c-'a'][a-1]<<'\n';
    }
}
