#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int>s;
    string str;
    int n, temp;
    cin>>n;
    while(n--){
        cin>>str;
        if(str=="push"){
            cin>>temp;
            s.push(temp);
        }
        else if(str=="pop") {
            if(!s.empty()){
                cout<<s.top()<<'\n';
                s.pop();
            }
            else
                cout<<"-1"<<'\n';
        }
        else if(str=="size")
            cout<<s.size()<<'\n';
        else if(str=="empty"){
            if(!s.empty())
                cout<<"0"<<'\n';
            else
                cout<<"1"<<'\n';
        }
        else if(str=="top"){
            if(!s.empty())
                cout<<s.top()<<'\n';
            else
                cout<<"-1"<<'\n';
        }
    }
}
