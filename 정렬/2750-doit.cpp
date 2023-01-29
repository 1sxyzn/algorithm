#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n,0);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    //버블 정렬
    for(int i=0; i<n-1; i++){ // 마지막 원소는 swap하지 않아도 딤, 이전 것 swap때 이미 처리되었기때문
        for(int j=0; j<n-1-i; j++){ // 뒤에서 i 번째 원소는 이미 정렬 됨 (큰수들)
            if(v[j]>v[j+1]){
                int temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<v[i]<<'\n';
    }
}
