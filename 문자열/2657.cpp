#include <iostream>

using namespace std;

int main(){
    int t; //테스트 케이스 수
    cin>>t;
    while (t--){
        int r; //반복 횟수
        cin>>r;
        string s;
        cin>>s;
        string p;
        for(int i=0; i<s.length(); i++){
            for(int j=0; j<r; j++){
                p+=s[i];
            }
        }
        cout<<p<<'\n';
    }
}
