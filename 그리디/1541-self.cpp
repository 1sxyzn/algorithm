#include<iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    int ans=0;
    int mid=0;
    int minus = 1;
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0' && s[i]<='9'){
            mid = mid*10 + (s[i]-'0');
        }
        else{ // 부호가 나온다면
            ans += minus * mid; // 앞에 연산해준 것 정답 값에 반영
            mid = 0; // 연산 다시 시작
            if(s[i]=='-') minus = -1;
        }
    }
    // 마지막 수 처리
    ans += minus * mid;
    cout<<ans;
}
