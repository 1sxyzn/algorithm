#include<iostream>
#include<queue>

using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a)==abs(b)){
            return a>b; // 절댓값 같으면 음수(더 작은 수)부터
        }
        else return abs(a)>abs(b); // 절댓값 다르면 절댓값 작은 것 부터
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;
    cin>>n;
    priority_queue<int, vector<int>, cmp>pq;
    while(n--){
        cin>>input;
        if(input==0){
            if(pq.empty()) cout<<"0"<<'\n';
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else{
            pq.push(input);
        }
    }
}
