#include<iostream>

using namespace std;

int main(){
    int a,b,c,i=0;
    cin>>a>>b>>c;
    if(b>=c) i=-1;
    else{
        //a+b*i<c*i => a<i*(c-b) => a/(c-b)<i 을 만족하는 최소 i 값, 즉 a/(b-c)+1인 값을 찾으면 된다.
        i=a/(c-b)+1;
    }
    cout<<i;
}
