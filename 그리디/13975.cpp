#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main(){
    int t, k;
    long long chap, y; //범위 주의
    int i; //임시변수
    
    cin>>t;
    while(t--){
        long long sum=0;
        cin>>k;
        priority_queue<long long, vector<long long>, greater<long long>> book;

        //입력
        for(i=0; i<k; i++){
            cin>>chap;
            book.push(chap);
        }

        //그리디 계산. 작은 두 수를 더하고 큐에 push 해주기
        while(book.size()!=1){ //마지막 최종 합 1개가 남으면 반복 종료
            y=book.top();
            book.pop();
            y+=book.top();
            book.pop();
            book.push(y);
            sum+=y;
        }
        cout<<sum<<'\n';
    }
}
