#include<iostream>
#include<deque>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n;
    deque<pair<int,int>>dq;
    for(int i=1; i<=n; i++){
        cin>>k;
        dq.emplace_back(i, k);
    }
    while(!dq.empty()){
        int value = dq.front().second;
        cout<<dq.front().first<<' ';
        dq.pop_front();
        if(value>0){
            value--;
            while(value--){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            value=-value;
            while(value--){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}
