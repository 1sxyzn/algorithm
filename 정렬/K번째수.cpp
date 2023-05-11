#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++){
        vector<int> temp;
        int s = commands[i][0]-1;
        int e = commands[i][1]-1;
        int k = commands[i][2]-1;
        for(int i=s; i<=e; i++){
            temp.push_back(array[i]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k]);
    }
    return answer;
}
