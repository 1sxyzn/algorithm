#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, value;
    cin>>n;
    vector<int>num(10001,0); // 카운팅 정렬, 계수 정렬
    for(int i=0; i<n; i++){
        cin>>value;
        num[value]++;
    }
    for(int i=0; i<10001; i++){
        while(num[i]>0){
            cout<<i<<'\n';
            num[i]--;
        }
    }
}
