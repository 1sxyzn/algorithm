#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int>&v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

int partition(vector<int>&v, int start, int end){ // pivot 구해서 return
    if((start+1)==end) { // 피봇 좌, 우에 해당하는 구간의 데이터가 2개인 경우, 바로 swap 해서 return
        if(v[start]>v[end]) swap(v, start, end);
        return end;
    }
    int mid = (start+end)/2;
    swap(v, mid, start); // a
    int pivot=v[start];

    int i=start+1, j=end;
    while(i<=j){
        while(pivot>v[i] && i<v.size()-1) i++;
        while(pivot<v[j] && j>0) j--;
        if(i<=j) swap(v, i++, j--);
    }
    swap(v, start,j); // a 에서 swap 한거 원상복귀
    return j;
}

void quickSort(vector<int>&v, int start, int end, int k){
    int pivot = partition(v, start, end);
    if(pivot == k) return;
    else if(pivot<k) quickSort(v,pivot+1,end,k); // pivot 오른쪽에 k 존재, 오른쪽 집중적으로 부분 정렬
    else quickSort(v,start,pivot-1,k); // pivot 왼쪽에 k 존재, 왼쪽 집중적으로 부분 정렬
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // 퀵 정렬 (pivot 정하고 이 기준으로 작은 값은 좌, 큰 값은 우에 두고 정렬될 때까지 pivot 변경)
    int n, k;
    cin>>n>>k;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    quickSort(v,0,n-1,k-1);
    cout<<v[k-1];
}
