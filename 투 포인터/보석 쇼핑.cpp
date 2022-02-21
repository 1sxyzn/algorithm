#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int>gemList(vector<string> gems, int n){
    int left=0, right=0;; //투포인터
    int size=gems.size();
    vector<int>ans = {1,size}; //출력 인덱스는 1부터 시작해야함 [1,n]
    map<string, int> m; //보석 이름과 갯수 저장
    m[gems[left]]++; //제일 처음 보석 카운트
    
    //왼쪽 포인터가 오른쪽 포인터를 넘지않고, 오른쪽 포인터가 범위 내 일때 반복
    while(left<=right && right<size){
        if(m.size()==n){ //현재 map에 모든 종류의 보석이 담겼을 때
            if(right-left<ans[1]-ans[0]) //현재 길이가 더 짧으면 갱신
                ans={left+1, right+1}; //인덱스는 1부터 시작하므로 +1 해서 저장
            left++;// 구간을 더 짧게할 수 있나 확인하기 위해 left 이동
            m[gems[left-1]]--;//left 이동시켰으므로 보석 갯수 빼주기
            if(m[gems[left-1]]==0) //보석 갯수 뺐는데 남은 보석이 0개라면
                m.erase(gems[left-1]); //해당 보석을 map에서 제거
        }
        else if (m.size()<n){ //모든 종류의 보석이 모인게 아니라면
            right++; //오른쪽 포인터 이동
            if(right==size) //포인터가 배열 범위 넘어가면
                break; //탐색 종료
            m[gems[right]]++; //오른쪽 포인터 이동시 있던 보석 count 
        }
    }
    
    return ans;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set <string> unique_gem;
    for(int i=0; i<gems.size(); i++){
        unique_gem.insert(gems[i]); //보석 종류를 알기 위해 중복된 보석 지운 set 이용
    }
    answer = gemList(gems, unique_gem.size());
    return answer;
}

//메인 함수 생략 - 프로그래머스에서 제공
