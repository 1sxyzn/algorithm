#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>v;
vector<int>memo;

int binarySearch(int val){
    int start=0, end=memo.size()-1;
    while(start<end){
        int mid = (start+end)/2;
        if(memo[mid]<val) start = mid+1;
        else end = mid;
    }
    return end; // memo 배열에서 val보다 크거나 같아지는 인덱스
}

void lis(int idx){
    memo.push_back(v[idx]);
    for(int i=1; i<v.size(); i++){
        if(memo[memo.size()-1] < v[i]){
            memo.push_back(v[i]);
        }
        else{
            memo[binarySearch(v[i])] = v[i];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    v.assign(n,0);
    for(int i=0; i<n; i++) cin>>v[i];

    lis(0);
    cout<<memo.size();
}
