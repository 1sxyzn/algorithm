#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    map<string,int> m;
    m["zero"]=0; m["one"]=1; m["two"]=2; m["three"]=3; m["four"]=4;
    m["five"]=5; m["six"]=6; m["seven"]=7; m["eight"]=8; m["nine"]=9;
    
    string num = "";
    for(int i=0; i<s.size(); i++){
        if(m[num]!=0 || num=="zero"){
            answer *= 10;
            answer += m[num];
            num = "";
        }
        if(s[i]>='0' && '9'>=s[i]){
            answer *= 10;
            answer += s[i]-'0';
        }
        else{
            num += s[i];
        }
    }
    if(m[num]!=0 || num=="zero"){
        answer *= 10;
        answer += m[num];
    }
    return answer;
}
