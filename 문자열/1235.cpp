#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n, ans;
    cin>>n;
    string s;
    vector<string>students(n);
    for(int i=0; i<n; i++){
        cin>>s;
        reverse(s.begin(), s.end());
        students[i]=s;
    }
    vector<pair<string, int>>check;
    // 놓친 반례 : 1번째 문자열과 2, 3, ... n 번째 문자열을 비교했는데 이 경우
    // 1번 문자열과 i와 다르고 j와도 다를 수도 있지만, i와 j가 같은 경우도 있다.
    for(int i=1; i<=students[0].length(); i++){
        //set에는 중복저장이 안됨
        //따라서 길이가 n인 문자열이 모두 겹치지 않는다면 n이 set의 size와 같을것이다 =>이걸 만족하는 길이 n을 찾자!
        //n보다 set의 size가 작으면, 중복 문자열이 있어서 저장되지 않음을 의미
        set<string>s;
        for(int k=0; k<n; k++){
            s.insert(students[k].substr(0,i));
        }
        if(s.size()==n){
            ans=i;
            break;
        }
    }
    cout<<ans;
}
