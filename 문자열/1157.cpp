#include <iostream>
#include <map>

using namespace std;

int main(){
    string word;
    cin>>word;
    map<char,int> al;
    int max=0;
    for(int i=0; i<word.length(); i++){
        if(word[i]<=122 && word[i]>=97){
            word[i]-=32;
        }
        al[word[i]]++;
        if(al[word[i]]>max)
            max=al[word[i]];
    }

    bool only=true;
    char ans;
    for(int i=0; i<word.length(); i++){
        if(al[word[i]]==max && only){
            ans=word[i];
            only=false;
        }
        else if(al[word[i]]==max && !only && word[i]!=ans) {
            ans='?';
            break;
        }
    }
    cout<<ans;
}
