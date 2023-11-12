#include<iostream>
#include<map>

using namespace std;

int main(){
    int n, ans=0;
    map<string,int> m;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s=="ENTER"){
            m.clear();
        }
        else{
            if(m[s]==0) {
                m[s]++;
                ans++;
            }
        }
    }
    cout<<ans;
}
