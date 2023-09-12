#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int zero = 0;
    while(s!="1"){
        cnt++;
        int ten = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='0') zero++;
            else ten++;
        }
        // ten to two
        string two = "";
        while(ten){
            if(ten%2==0) two.push_back('0');
            else two.push_back('1');
            ten /= 2;
        }
        s = two;
    }
    answer.push_back(cnt);
    answer.push_back(zero);
    return answer;
}
