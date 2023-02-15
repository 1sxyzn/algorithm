#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, ans=0;
    cin>>n;
    priority_queue<int>plus;
    priority_queue<int, vector<int>, greater<>>minus;
    int zero=0;
    int one=0; // 1은 다른거랑 곱하는 것 보다 더하는게 연산 결과가가 큼
    while(n--){
        cin>>k;
        if(k==1) one++;
        else if(k==0) zero++;
        else if(k<0) minus.push(k);
        else plus.push(k);
    }

    while(minus.size()>1){
        int a=minus.top();
        minus.pop();
        int b=minus.top();
        minus.pop();
        ans+=(a*b);
    }
    if(minus.size()==1 && zero==0) ans+=minus.top();

    while(plus.size()>1){
        int a=plus.top();
        plus.pop();
        int b=plus.top();
        plus.pop();
        ans+=(a*b);
    }
    if(plus.size()==1) ans+=plus.top();

    ans+=one;
    cout<<ans;
}
