#include<iostream>
#include<vector>

using namespace std;

int main(){
    // 삽입 정렬
    int n, ans=0;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    for(int i=1; i<n; i++){
        int insert=-1, data=v[i];
        for(int j=0; j<i; j++){
            if(v[j]>v[i]){ // 오름차순, 앞에 더 큰게 있는지 확인
                insert=j;
                break;
            }
        }
        if(insert==-1) continue;
        // 바꿀 데이터 (i) 앞에 있으면서도, insert 뒤에 있는 데이터 미루기
        for(int k=i; k>insert; k--){
            v[k]=v[k-1];
        }
        v[insert]=data;
    }

    vector<int>sum(n,0);
    sum[0]=v[0];
    for(int p=1; p<n; p++){
        sum[p]=sum[p-1]+v[p];
    }

    for(int q=0; q<n; q++){
        ans+=sum[q];
    }
    cout<<ans;
}
