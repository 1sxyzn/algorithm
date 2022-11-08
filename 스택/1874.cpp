#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt=1;
    stack<int> s;
    vector<char>answer;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        // 입력된 값이 커서 계속 push 해야할 경우
        while(cnt<=num) {
            s.push(cnt);
            answer.push_back('+');
            cnt++;
        }
        // 이제 꺼낼 차례인데 스택이 비어있거나, 꺼낼 수 있는 수보다 큰 값을 꺼내라고하면 NO
        if(s.empty() || s.top()<num){
            cout<<"NO"<<'\n';
            return 0;
        }

        // 꺼내고 싶은 원소가 스택 아래 깔려있다면, 위의 원소 갯수 만큼 pop 해주어야 함
        while(s.top()>num){
            s.pop();
            answer.push_back('-');
        }

        // 원하는 원소를 찾으면 pop
        // ++ 29 번째 while 과 아래 코드를 합칩고 싶었으나
        // ++ 17번째 줄의 while문이 끝나고, 아래 코드가 실행될 수 있으므로
        // ++ 합치기 실패
        if(s.top()==num){
            s.pop();
            answer.push_back('-');
        }
    } // Q 중복되는 코드를 합치는 방법이 있을까?

    for(int a=0; a<answer.size(); a++){
        cout<<answer[a]<<'\n';
    }
}
