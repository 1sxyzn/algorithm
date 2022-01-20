#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
 누를 때, 뗄 때를 카운드 하기
 누를 때 = 높은 프렛 or 새 프렛 or 새 줄을 연주할 때
 뗄 때 = 현재 최고 프렛 보다 낮은 프렛을 연주하고 싶을 때

 줄을 넘어갈 때는 다른 줄의 손을 떼지 않아도 된다.
 */

int main(){
    vector<stack<int>> g (7); //기타 1~7 번출
    int n, p;
    int s, f; //기타 스트링과 프렛
    int cnt=0;

    cin>>n>>p;

    while(n--){
        cin>>s>>f;
        //프렛에서 손 떼기
        //누르려는 프렛에 이미 다른게 눌려있고, 그 프렛이 내가 누르려는 프렛보다 높다면 떼기
        while(!g[s].empty() && g[s].top()>f){
            cnt++;
            g[s].pop();
        }

        //프렛 누르기
        //그 줄이 비어있거나, 누르려는 줄에 원하는 프렛이 눌려 있지 않으면
        if(g[s].empty() || g[s].top() != f){
            cnt++;
            g[s].push(f);
        }
    }
    cout<<cnt<<'\n';
}
