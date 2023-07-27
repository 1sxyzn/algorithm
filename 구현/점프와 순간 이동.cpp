#include <iostream>
#include <vector>

using namespace std;

int solution(int n)
{
    int ans = 0;
    while(n){ // 최대 10억
        if(n%2==0) n/=2;
        else {
            n--;
            ans++;
        }
    }
    return ans;
}
