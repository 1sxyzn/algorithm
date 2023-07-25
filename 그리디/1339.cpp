#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;

    map<int,int>al; // weight
    vector<pair<int,int>>calc; // sorting
    vector<string> origin; // data

    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        origin.push_back(s);
        int digit=1;
        for(int j=s.length()-1; j>=0; j--){
            al[s[j]-'A'] += digit;
            digit *= 10;
        }
    }

    for(int i=0; i<26; i++){
        if(al[i]>0){
            calc.push_back({al[i],i});
        }
    }

    sort(calc.begin(), calc.end(), greater<>());

    int cur = 9;
    for(int i=0; i<calc.size(); i++){
        al[calc[i].second] = cur;
        cur--;
    }

    int ans=0;
    for(int i=0; i<origin.size(); i++){
        int temp=0;
        for(int j=0; j<origin[i].length(); j++){
            temp += al[origin[i][j]-'A'];
            temp*=10;
        }
        ans += (temp/10);
    }

    cout<<ans;
}
