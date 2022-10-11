#include <iostream>
using namespace std;
int main(){
    int ans=0;
    string s;
    getline(cin,s);
    for(int i=0; i<s.length(); i++){
        if(i!=0 && i!=s.length()-1 && s[i]==' '){
            ans++;
        }
    }
    if(s==" ") ans--;
    cout<<ans+1;
}
