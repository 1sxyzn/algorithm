#include <iostream>

using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    int m=a*b;

    //최대공약수, 유클리드 호제법
    while(b){
        int t=a%b;
        a=b;
        b=t;
    }
    cout<<a<<"\n";

    //최소공배수
    //a * b = 최대공약수 * 최소공배수
    cout<<m/a<<"\n";
}
