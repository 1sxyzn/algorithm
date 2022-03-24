#include<iostream>

using namespace std;

int calc(string s){
    int ans=0;
    //만약 숫자가 계속 나오면 이전숫자 * 10 + 현재숫자 해서 자릿수를 맞춰주고,
    //부호가 나오면 계산, 이때 한번이라도 - 가 나오면 그 뒤의 숫자는 다 뺄셈
    int before = 0; //자리수 맞출 변수
    bool flag = false; //-가 나왔는지 체크할 변수
    for(int i=0; i<s.size(); i++){
        if(s[i]-'0'>=0 && s[i]-'0'<=9){ //자릿값 맞춰주기
            before = before * 10;
            if(flag) //한번이라도 - 가 나왔으면 뒤에는 모두 뺄셈
                before-=s[i]-'0';
            else //+ 만 나온 상태면 계속 더해주기
                before+=s[i]-'0';
        }
        else{
            ans+=before; //누적 계산
            before = 0; //계산 했으니, 다시 일의 자리 수 부터 계산을 이어가기 위해 초기화
            if(s[i]=='-')
                    flag = true;
            }
        }
    //맨 마지막 수 계산
    ans+=before;
    return ans;
}

int main(){
    string s;
    cin>>s;

    cout<<calc(s)<<'\n';
}
