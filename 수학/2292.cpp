#include<iostream>
using namespace std;
int main(){
    int n;
    int sum=1;
    cin>>n;
    for(int i=1; ; i++) {
        if (sum >= n) {
            cout << i;
            break;
        }
        sum += 6 * i;
    }
}
