#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int p1=1, p2=1, sum=1;
    while(p1<=p2 && p2<=10000){
        if(sum<n){
            p2++;
            sum+=p2;
        }
        else if(sum>n){
            sum-=p1;
            p1++;
        }
        else{
            answer++;
            sum-=p1;
            p1++;
            p2++;
            sum+=p2;
        }
    }
    return answer;
}
