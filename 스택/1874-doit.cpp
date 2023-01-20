#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int n, num, cnt=1;
    cin>>n;
    stack<int>s;
    vector<char>ans;
    for(int i=1; i<=n; i++){
        cin>>num;
        if(cnt<=num){
            while(cnt<=num){
                s.push(cnt);
                ans.push_back('+');
                cnt++;
            }
            ans.push_back('-');
            s.pop();
        }
        else{ // cnt>num
            if(num<=s.top()){
                s.pop();
                ans.push_back('-');
            }
            else{ // num>s.top() && cnt>num == 수열이 만들어질 수 없는 상황
                cout<<"NO";
                break;
            }
        }
        if(i==n){
            for(int j=0; j<ans.size(); j++){
                cout<<ans[j]<<'\n';
            }
        }
    }
}
