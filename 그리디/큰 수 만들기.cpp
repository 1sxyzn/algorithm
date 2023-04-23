#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.size();
    stack<int>s;
    for(int i=0; i<n; i++){
        // 스택 비어있지 않고, 다음에 들어오는 수가 더 크고, 제거할 수 있는 횟수가 남아있다면
        while(!s.empty() && s.top()<number[i]-'0' && k>0) {
            s.pop(); // 맨 앞자리 수 제거
            k--;
        }
        s.push(number[i]-'0');
    }
    while(!s.empty()){
        if(s.size()<=(n-k)){ // 제거할 수 있는 횟수가 남아있다면 맨 뒷 자리수 제거
            answer += s.top()+'0';
        }
        s.pop();
    }
    reverse(answer.begin(), answer.end()); // stack이므로 문자열 뒤집기
    return answer;
}
