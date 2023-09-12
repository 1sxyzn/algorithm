#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char,int> score;
    for(int i=0; i<survey.size(); i++){
        char nega = survey[i][0];
        char posi = survey[i][1];
        if(choices[i]<4){ // 비동의
            score[nega] += (4-choices[i]);
        }
        else if(choices[i]>4){ // 동의 (-4하기)
            score[posi] += (choices[i]-4);
        }
    }
    if(score['R']>= score['T']) answer += 'R'; else answer += 'T';
    if(score['C']>= score['F']) answer += 'C'; else answer += 'F';
    if(score['J']>= score['M']) answer += 'J'; else answer += 'M';
    if(score['A']>= score['N']) answer += 'A'; else answer += 'N';
    return answer;
}
