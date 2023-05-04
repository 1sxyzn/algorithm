#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    vector<int>lion;
    int doll;
    for(int i=0; i<n; i++){
        cin>>doll;
        if(doll==1){
            lion.push_back(i);
        }
    }
    long long ans = LONG_LONG_MAX;
    for(int i=k-1; i<lion.size(); i++){
        if(lion[i] - lion[i-(k-1)] + 1 < ans) ans = lion[i] - lion[i-(k-1)] + 1;
    }
    if(ans==LONG_LONG_MAX) cout<<-1;
    else cout<<ans;
}
