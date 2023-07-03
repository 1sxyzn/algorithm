#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp_ii(pair<int,int>a, pair<int,int>b){
    if(a.first!=b.first){
        return a.first>b.first;
    }
    else return a.second<b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // map
    map<string, int>m;
    for(int i=0; i<genres.size(); i++){
        m[genres[i]]+=plays[i];
    }

    vector<pair<int,string>> gr;
    for(auto iter:m){
        gr.push_back({iter.second, iter.first});
    }
    sort(gr.begin(), gr.end(), greater<>());
    
    for(int i=0; i<gr.size(); i++){
        vector<pair<int,int>> v; // 재생횟수, 고유번호
        for(int j=0; j<genres.size(); j++){
            if(genres[j] == gr[i].second){
                v.push_back({plays[j],j});
            }
        }
        sort(v.begin(), v.end(), cmp_ii);
        answer.push_back(v[0].second);
        if(v.size()>1) answer.push_back(v[1].second);
    }
    return answer;
}
