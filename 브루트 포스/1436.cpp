#include<iostream>

using namespace std;

int main() {
    int n, i;
    cin>>n;
    //브루트 포스
    int cnt=0;
    for(i=666; ; i++){
        string s= to_string(i); //문자열로 바꾸는 함수
        //해당 문자열에서 666' 찾지 못하면 npos값, 즉 -1이 리턴된다
        if(s.find("666") != s.npos) //문자열에 666이 있으면
            cnt++;
        if(cnt==n)
            break;
    }
    cout<<i<<'\n';
}
