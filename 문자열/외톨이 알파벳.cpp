#include <string>
#include <vector>

using namespace std;

string solution(string input_string) {
    string answer = "";
    vector<vector<int>>al(26,vector<int>(0));
    for(int i=0; i<input_string.size(); i++){
        al[input_string[i]-'a'].push_back(i);
    }
    for(int i=0; i<26; i++){
        if(al[i].size()>=2){
            for(int j=1; j<al[i].size(); j++){
                if(al[i][j]-al[i][j-1]>1){
                    answer+=(char)(i+'a');
                    break;
                }
            }
        }
    }
    if(answer=="") return "N";
    return answer;
}
