#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        int find;
        cin>>find;
        int start=0, end=n-1, mid;
        bool check=false;
        while(start<=end){
            mid = (start+end)/2;
            if(v[mid]==find){
                check = true;
                break;
            }
            else if(v[mid]<find){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        cout<<check<<'\n';
    }
}
