#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int>q;
    string cmd;

    int n, x;
    cin>>n;
    while(n--){
        cin>>cmd;
        if(cmd=="push"){
            cin>>x;
            q.push(x);
            continue;
        }
        else if(cmd=="pop" && !q.empty()){
                cout<<q.front();
                q.pop();
        }
        else if(cmd=="empty") {
            if(q.empty()) cout<<1;
            else cout<<0;
        }
        else if(cmd=="size") cout<<q.size();
        else if(cmd=="front" && !q.empty()) cout<<q.front();
        else if(cmd=="back" && !q.empty()) cout<<q.back();
        else cout<<-1;
        cout<<'\n';
    }
}
