#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> student(n+1, 1); //모두 1개씩 가지고 있다고 초기화
    
    // 잃어버린 학생
    for(int i=0; i<lost.size(); i++)
        student[lost[i]]--;
    
    //여분의 체육복을 가진 학생
    for(int i=0; i<reserve.size(); i++)
        student[reserve[i]]++;
    
    //왼쪽 학생의 체육복부터 빌리기
    for(int i=1; i<=n; i++){
        if(student[i]!=0) //체육복이 있는 학생
            continue;
        
        if(student[i-1]==2) { //왼쪽 학생이 여분의 체육복이 있으면
            student[i-1]--;
            student[i]++;
        }
        else if(student[i+1]==2){ //왼쪽 학생에게 못빌려서 오른쪽 학생에게 빌릴 경우
            student[i+1]--;
            student[i]++;
        }
    }
    
    int answer = 0;
    for(int i=1; i<=n; i++){
        if(student[i]>=1)
            answer++;
    }
    return answer;
}

//메인 함수 생략 - 프로그래머스에서 제공
