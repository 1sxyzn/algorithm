#include<iostream>
#include<vector>

using namespace std;

vector<int>v;
vector<int>temp;

void merge_sort(int start, int end){ // 병합 정렬
    if(end-start<1) return;

    int mid = start + (end-start)/2;
    merge_sort(start, mid);
    merge_sort(mid+1,end);

    for(int i=start; i<end+1; i++){
        temp[i]=v[i];
    }

    int idx=start; // 병합할 때 쓰일 원래 벡터 v의 인덱스
    int p1=start;
    int p2=mid+1;

    while(p1<=mid && p2<=end){
        if(temp[p1]<temp[p2]){
            v[idx]=temp[p1]; // 더 작은 쪽의 값 저장
            p1++;
            idx++;
        }
        else{
            v[idx]=temp[p2];
            p2++;
            idx++;
        }
    }
    // 한 쪽은 병합이 다 되고, 다른 쪽은 병합이 안 되었을 경우
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
    cout.tie(NULL);

    int n;
    cin>>n;
    v.assign(n,0);
    temp.assign(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    merge_sort(0,n-1);

    for(int i=0; i<n; i++){
        cout<<v[i]<<'\n';
    }
}
