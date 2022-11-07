#include <iostream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;
    set<int>s;
    cin>>n;
    while(n--){
        cin>>i;
        s.insert(i);
    }
    cin>>m;
    while(m--){
        cin>>i;
        auto it = s.find(i);
        if(it==s.end()) cout<<0<<' ';
        else cout<<1<<' ';
    }
}
