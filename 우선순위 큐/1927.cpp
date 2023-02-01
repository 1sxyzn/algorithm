#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n;

    priority_queue<int, vector<int>, greater<int>>pq;
    while(n--){
        cin>>m;
        if(pq.empty() && m==0) cout<<0<<'\n';
        else if(!pq.empty() && m==0){
            cout<<pq.top()<<'\n';
            pq.pop();
        }
        else pq.push(m);
    }
}
