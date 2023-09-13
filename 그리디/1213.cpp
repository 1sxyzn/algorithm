#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int main(){
    string s;
    cin>>s;
    map<int,int>al;
    for(int i=0; i<s.length(); i++){
        al[s[i]-'A']++;
    }

    int odd_cnt=0;
    int middle;
    string half;
    for(int i=0; i<26; i++){
        if(al[i]%2==1) {
            odd_cnt++;
            middle = i;
            if(odd_cnt>1){
                cout<<"I'm Sorry Hansoo";
                return 0;
            }
        }
        if(al[i]>1 || al[i]%2==0){ // 홀수개 알파벳인데 1개 이상 존재하거나, 짝수개 있는 알파벳
            for(int j=0; j<al[i]/2; j++){
                half += 'A'+i;
            }
        }
    }
    string ans = half;
    if(odd_cnt==1) ans += 'A'+middle;
    reverse(half.begin(), half.end());
    ans += half;
    cout<<ans;
}
