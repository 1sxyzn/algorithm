#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int done=0; // 다 된 작업을 가리키는 idx
    while(done < progresses.size()){
        if(progresses[done]>=100){ // 진척도가 100이 넘으면
            int cnt=0; // 해당 배포일에 몇 개 배포할 수 있는지 카운트
            while(progresses[done]>=100){
                cnt++;
                done++;
                if(done == progresses.size()){ // 마지막 직업까지 배포한 경우
                    break;
                }
            }
            answer.push_back(cnt);
        }
        for(int i=0; i<progresses.size(); i++){ // 100%가 될 때 까지 진척도 더하기
            progresses[i] += speeds[i];
        }
    }
    return answer;
}
