#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, bool>m;
    int ans=0;
    string s;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        string temp;
        for(int j=i; j<s.size(); j++){
            temp+=s[j];
            if(!m[temp]){
                m[temp]=true;
                ans++;
            }
        }
    }
    cout<<ans;
}
