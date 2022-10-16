#include <iostream>
using namespace std;
int main(){
    // 홀수 대각선은  3/1 2/2 1/3 처럼 분자 줄어들고 분모 up
    // 짝수 대각선은  1/2 2/1 처럼 분자 늘어나고 분모 줄어든다
    int x;
    cin>>x;
    // 알아야하는 것
    // 몇번째 줄 대각선인지, 그 줄의 몇번째 분수인지
    int i=1;
    while(x-i>0){
        x-=i; // 한 대각선 씩 빼주고 나머지 대각
        i++;
    }
    //i 번째 대각선의 x 번째 분수
    if(i%2==1)
        cout<<i-x+1<<'/'<<x;
    else
        cout<<x<<'/'<<i-x+1;
}
