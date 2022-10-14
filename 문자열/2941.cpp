#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<string>cro={"c=","c-","dz=","d-","lj","nj","s=","z="};
    string s;
    cin>>s;
    for(int i=0; i<8; i++){
        while(s.find(cro[i])!=string::npos) // find는 단어가 없으면 string::npos 반환
        s.replace(s.find(cro[i]),cro[i].length(),"#"); // 단어가 있으면 #로 변환
    }
    cout<<s.length();
}
