#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>input; // 카드에 적힌 정수 저장
    vector<bool>check(1000001,false); // 등장 여부
    vector<int>score(1000001,0); // 점수 저장

    int n, MAX=0;
    cin>>n;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        input.push_back(t);
        check[t]=true;
        MAX = max(MAX, t);
    }

    for(int k=0; k<n; k++){
        int i = input[k];
        for(int j=i+i; j<=MAX; j+=i){
            if(check[j]){
                score[i]++;
                score[j]--;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<score[input[i]]<<' ';
    }
}
