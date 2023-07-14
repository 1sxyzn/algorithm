#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> name; // user id & name
    vector<pair<string,string>> chat; // user id & action
    
    for(int i=0; i<record.size(); i++){
        int idx = record[i].find(' ');
        string act = record[i].substr(0, idx);
        string data = record[i].substr(idx+1, record[i].length());
        string id, nick;
        
        if(act != "Leave"){
            idx = data.find(' ');
            id = data.substr(0, idx);
            nick = data.substr(idx+1, data.length());
            name[id] = nick;            
        }
        
        else{
            id = data;
        }
        
        chat.push_back({id, act});
    }
    
    for(int i=0; i<chat.size(); i++){
        string s = "";
        s += name[chat[i].first];
        if(chat[i].second=="Enter"){
            s += "님이 들어왔습니다.";
        }
        else if(chat[i].second=="Leave"){
            s += "님이 나갔습니다.";
        }
        else continue; // change 인 경우
        answer.push_back(s);
    }
    return answer;
}
