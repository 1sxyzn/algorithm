#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    queue<int>q;
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    while(q.size()>1){
        q.pop(); // 맨 위의 것 버리기
        q.push(q.front()); // 이후 위의 것 뒤로 옮기기
        q.pop(); 
    }
    cout<<q.front();
}#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    queue<int>q;
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    while(q.size()>1){
        q.pop(); // 맨 위의 것 버리기
        q.push(q.front()); // 이후 위의 것 뒤로 옮기기
        q.pop(); 
    }
    cout<<q.front();
}
