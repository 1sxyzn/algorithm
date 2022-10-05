#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v(42,0);
    int n;
    for(int i=0; i<10; i++){
        cin>>n;
        v[n%42]++;
    }
    int sum=0;
    for(int i=0; i<42; i++){
        if(v[i]>0) sum++;
    }
    cout<<sum;
}
