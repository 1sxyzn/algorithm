#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string,int>m;
    
    m[words[0]]++;
    for(int i=1; i<words.size(); i++){
        if(words[i][0]!=words[i-1][words[i-1].length()-1] || m[words[i]]!=0){
            if((i+1)%n ==0) {
                answer.push_back(n);
                answer.push_back((i+1)/n);
            }
            else {
                answer.push_back((i+1)%n);
                answer.push_back(((i+1)/n)+1);
            }
            break;
        }
        m[words[i]]++;
    }
    
    if(answer.size()==0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
