#include<iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    int ans=0;
    int val=0;
    bool minus=false;
    
    for(int i=0; i<s.length(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            val *= 10;
            val += s[i] - '0';
        }
        else {
            if (minus) ans -= val;
            else ans += val;
            val=0;
            if (s[i] == '-') minus = true;
        }
    }
    // 마지막 수 처리
    if(minus) ans-=val;
    else ans+=val;
    cout<<ans;
}
