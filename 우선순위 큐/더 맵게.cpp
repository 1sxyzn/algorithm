#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i=0; i<scoville.size(); i++){
        pq.push(scoville[i]);
    }

    //섞지 않아도 바로 K를 만족하는 경우
    if(pq.top() >= K){
        return answer;
    }

    //섞어야 하는 경우
    int scv;
    while(pq.size()>=2){
        scv = pq.top();
        pq.pop();
        scv += (pq.top()*2);
        pq.pop();
        pq.push(scv);

        answer++;

        if(pq.top() >= K){
            return answer;
        }
    }
    return -1;
}
