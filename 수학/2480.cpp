#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int>v(3,0);
    for(int i=0; i<3; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    if(v[0]==v[2]) {
        cout<<10000+v[0]*1000;
    }
    else if(v[0]==v[1] || v[1]==v[2]){
        cout<<1000+v[1]*100;
    }
    else{
        cout<<v[2]*100;
    }
}
