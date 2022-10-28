#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int h,w,n;
        cin>>h>>w>>n;
        int front=n%h;
        int back=n/h+1;
        if(front==0){
            front=h;
            back-=1;
        }
        cout<<front;
        if(back<10)
            cout<<"0";
        cout<<back<<'\n';
    }
}
