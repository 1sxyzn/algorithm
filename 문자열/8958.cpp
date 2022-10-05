#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int combo=0;
        int sum=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='X'){
                combo=0;
            }
            else{
                combo++;
                sum+=combo;
            }
        }
        cout<<sum<<'\n';
    }
}
