#include<iostream>
#include <string>
#include <vector>
#include<stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    vector<stack<int>> vs(n); //5,1 - 4,1 - 3,1 ...
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=0; j--){
            if(board[j][i]!=0)
                vs[i].push(board[j][i]);
        }
    }
    
    stack<int>res;
    for(int i=0; i<moves.size(); i++){
        int cur_idx = moves[i]-1;
        // res 비어있거나,res top 과 cur top 이 다르  push 만
        // res top 과 cur top 이 같으면 answer++ 후 pop
        if(vs[cur_idx].empty()) continue;
        if(res.empty() || res.top()!=vs[cur_idx].top()) {
            res.push(vs[cur_idx].top());
        }
        else {
            answer++;
            res.pop();
        }
        vs[cur_idx].pop();
    }
    return answer*2;
}
