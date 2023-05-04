#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ans=0;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        long long now = v[i];
        int p1 = 0;
        int p2 = n-1;
        while(p1<p2){
            if(v[p1]+v[p2] == now) {
                if(p1!=i && p2!=i) { // 자기 자신을 합의 요소로 사용하면 안됨
                    ans++;
                    break;
                }
                else if(p1==i) p1++;
                else p2--;
            }
            else if(v[p1]+v[p2] < now) p1++;
            else p2--;
        }
    }
    cout<<ans;
}
