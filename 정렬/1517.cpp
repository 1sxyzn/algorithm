#include<iostream>
#include<vector>

using namespace std;

vector<int>v;
vector<int>temp;
long long result=0;

void merge_sort(int start, int end){
    if(end-start<1) return;

    int mid=start+ (end-start)/2;
    merge_sort(start,mid);
    merge_sort(mid+1,end);

    for(int i=start; i<end+1; i++){
        temp[i]=v[i];
    }

    int idx=start;
    int p1=start;
    int p2=mid+1;

    while(p1<=mid && p2<=end){
        if(temp[p1]<=temp[p2]){ // == 일 경우는 swap이 일어나지 않음
            v[idx]=temp[p1];
            p1++;
            idx++;
        }
        else{
            v[idx]=temp[p2];
            result+=(p2-idx); // 뒷 배열에서 숫자가 앞으로 오는 경우 (이전 인덱스 - 새 인덱스)
            p2++;
            idx++;
        }
    }
    while(p1<=mid){
        v[idx]=temp[p1];
        p1++;
        idx++;
    }
    while(p2<=end){
        v[idx]=temp[p2];
        p2++;
        idx++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    v.assign(n,0);
    temp.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    merge_sort(0,n-1);
    cout<<result<<'\n';
}
