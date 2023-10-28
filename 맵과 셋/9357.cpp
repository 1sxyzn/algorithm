#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t, n;
    cin>>t;
    while(t--){
        int ans = 1;
        map<string,int>check_name; // 의상 이름 중복 체크
        map<string,int>check_category; // 종류 갯수 저장
        vector<string>v; // 종류 저장
        cin>>n;
        if(n==0) {
            cout<<0<<'\n';
            continue;
        }
        string name, category;
        while(n--){
            cin>>name>>category;
            if(check_name[name]==0){
                check_name[name]++;
                check_category[category]++;
                v.push_back(category);
            }
        }
        if(v.size()==1) cout<<1<<'\n';
        else{
            sort(v.begin(), v.end());
            ans *= (check_category[v[0]]+1);
            for(int i=1; i<v.size(); i++){
                if(v[i]!=v[i-1]){
                    ans *= (check_category[v[i]]+1);
                }
            }
            cout<<ans-1<<'\n';
        }
    }
}
