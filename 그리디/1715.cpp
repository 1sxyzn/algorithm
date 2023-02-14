#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n, k, ans=0; cin>>n;
    priority_queue<int, vector<int>, greater<>>pq;
    for(int i=0; i<n; i++){
        cin>>k;
        pq.push(k);
    }
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    cout<<ans;
}
