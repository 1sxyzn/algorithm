#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    stack<int>idx;
    vector<int>v(n,0);
    vector<int>ans(n,0);

    cin>>v[0];
    idx.push(0); // 처음 인덱스 저장

    for(int i=1; i<n; i++){
        cin>>v[i];
        while(!idx.empty() && v[idx.top()]<v[i]){ // num이 누군가의 오큰수인 경우
            ans[idx.top()]=v[i]; // 오큰수를 찾으면 저장하고, 찾은 애들은 pop
            idx.pop();
        }
        idx.push(i); // 오큰수를 찾지 못한 수들을 모두 push
    }
    while(!idx.empty()){ // 오큰수가 없는 수들
        ans[idx.top()]=-1;
        idx.pop();
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<' ';
    }
}
