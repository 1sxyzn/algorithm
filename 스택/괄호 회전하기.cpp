#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool check(string s, int n){
    stack<char> st;
    for(int i=0; i<n; i++){
        if(s[i]=='{'||s[i]=='['||s[i]=='('){
            st.push(s[i]);
        }
        
        else if(s[i]=='}'){
            //or 순서가 바뀌면 segmentation fault (core dumped)
            if(st.empty()||st.top()!='{'){ 
                return false;
            }
            else st.pop();
        }
        
        else if(s[i]==']'){
            if(st.empty()||st.top()!='['){
                return false;
            }
            else st.pop();
        }
        
        else if(s[i]==')'){
            if(st.empty()||st.top()!='('){
                return false;
            }
            else st.pop();
        }
    }
    if(!st.empty())
            return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    int n = s.size();
    for(int i=0; i<n; i++){
        string temp = "";
        temp+=s.substr(i,n-i);
        temp+=s.substr(0,i);
        if(check(temp, n))
            answer++;
    }
    return answer;
}
