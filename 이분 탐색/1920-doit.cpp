#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n;
    vector<int>a(n,0);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());

    cin>>m;
    for(int i=0; i<m; i++){
        int value;
        cin>>value;

        int find=0; // flag
        int start=0, end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(a[mid]==value) {
                find=1;
                break;
            }
            else if(a[mid]<value) start=mid+1;
            else end=mid-1;
        }
        cout<<find<<'\n';
    }
}
