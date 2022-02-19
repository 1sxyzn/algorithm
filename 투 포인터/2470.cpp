#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

pair<int, int> zero(int left, int right, vector<int>v){
    pair<int, int>ans;
    int diff = 2 * 1e9 + 1;

    //left가 right보다 작으면
    while(left<right){
        int sum = v[left]+v[right]; //용액의 합
        if(sum==0)
            return make_pair(v[left], v[right]);
        if(abs(sum)<diff) { //현재 최소차이보다 더 작으면 최소차이 갱신
            diff=abs(sum);
            ans= make_pair(v[left],v[right]);
        }
        if(sum>0)
            right--;
        else
            left++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n,0);
    for(int i=0; i<n; i++)
        cin>>v[i];

    sort(v.begin(),v.end());
    pair<int,int> ans = zero(0, n-1, v);
    cout<<ans.first<<" "<<ans.second<<'\n';
}
