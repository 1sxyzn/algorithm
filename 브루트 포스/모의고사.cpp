#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int>fir = {1, 2, 3, 4, 5};
    vector<int>sec = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int>th = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<pair<int,int>>cnt(3,{0,0});
    for(int i=0; i<3; i++){
        cnt[i].second = i+1;
    }
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==fir[i%fir.size()]) cnt[0].first++;
        if(answers[i]==sec[i%sec.size()]) cnt[1].first++;
        if(answers[i]==th[i%th.size()]) cnt[2].first++;
    }
    sort(cnt.begin(), cnt.end(), greater<>());
    int m = cnt[0].first;
    for(int i=0; i<3; i++){
        if(cnt[i].first==m) answer.push_back(cnt[i].second);
    }
    sort(answer.begin(),answer.end());
    return answer;
}
