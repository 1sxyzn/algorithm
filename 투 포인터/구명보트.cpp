#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int p1=0, p2=people.size()-1, cur=0; // 현재 탑승한 사람 cur
    while(p1<p2){
        if(people[p1] + people[p2] <= limit){
            p1++;
            p2--;
            cur+=2;
        }
        else{
            p2--;
            cur++;
        }
        answer++;
    }
    if(cur!=people.size()) answer++; // 탑승인원이랑 현재인원이랑 다르면 못탄 사람 태우기 (못탄 이유: 포인터 이동 시 p1==p2가 되어 누락된 사람)
    return answer;
}
