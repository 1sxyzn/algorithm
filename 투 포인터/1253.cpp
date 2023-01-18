#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, ans=0;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++){
        long long find = v[i];
        int p1=0, p2=n-1; // 투 포인터
        while(p1<p2){
            if(v[p1]+v[p2]==find){
                // 자기 자신을 포인터가 가리키는 경우
                if(p1!=i && p2!=i){
                    ans++; break;
                }
                else if(p1==i) p1++;
                else p2--;
            }
            else if(v[p1]+v[p2]<find){
                p1++;
            }
            else{
                p2--;
            }
        }
    }
    cout<<ans;
}
