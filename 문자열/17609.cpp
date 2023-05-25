#include<iostream>

using namespace std;

string str;

bool palindrome(int s, int e){
    while(s<e){
        if(str[s]==str[e]){
            s++;
            e--;
        }
        else return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    while(n--){
        cin>>str;
        int ans=0;
        int p1=0;
        int p2=str.size()-1;
        while(p1<p2){
            if(str[p1]==str[p2]){
                p1++;
                p2--;
            }
            else{
                if(palindrome(p1+1, p2)) ans=1;
                else if(palindrome(p1, p2-1)) ans=1;
                else ans=2;
                break;
            }
        }
        cout<<ans<<'\n';
    }
}
