#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int>v;
    for(int i=0; i<s.length(); i++){
        v.push_back(s[i]-'0');
    }

    for(int i=0; i<v.size(); i++){ // 선택정렬
        int max=i;
        for(int j=i+1; j<v.size(); j++){
            if(v[max]<v[j]){ // 제일 큰 값을 골라서 앞에 배치
                max=j;
            }
        }
        int temp=v[i];
        v[i]=v[max];
        v[max]=temp;
    }

    for(int i=0; i<v.size(); i++){
        cout<<v[i];
    }
}
