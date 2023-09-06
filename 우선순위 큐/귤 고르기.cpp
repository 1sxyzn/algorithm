#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int,int> m;
    for(int i=0; i<tangerine.size(); i++){
        m[tangerine[i]]++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for(int i=1; i<=10000000; i++){
        if(m[i]!=0) pq.push({m[i],i});
    }
    int out = tangerine.size() - k;
    while(!pq.empty()){
        int c = pq.top().first;
        if(out-c>0){
            pq.pop();
            out -= c;
        }
        else {
            if(out==c) pq.pop();
            break;
        }
    }
    answer = pq.size();
    return answer;
}
