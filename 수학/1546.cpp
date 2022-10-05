#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, max=0;
    cin>>n;
    vector<double> v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(v[i]>max) max=v[i];
    }
    double sum=0;
    for(int i=0; i<n; i++){
        v[i]=v[i]/max*100;
        sum+=v[i];
    }
    cout<<sum/v.size();
}
