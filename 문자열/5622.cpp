#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int>v={3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
    string s;
    int sum=0;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        sum+=v[s[i]-'A'];
    }
    cout<<sum;
}
