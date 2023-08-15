#include<iostream>
#include<vector>

using namespace std;

// x^2 - y^2 = G 일 때, x 찾기

int main(){
    int g;
    cin>>g;
    vector<int>ans;

    int p1=1, p2=2;
    while(true){
        if(p2*p2 - p1*p1 == g){
            ans.push_back(p2);
            p2++; p1++;
        }
        else if (p2*p2 - p1*p1 < g) p2++;
        else{
            p1++;
            if(p1==p2) p2++;
        }

        if(p2*p2 - (p2-1)*(p2-1) > 100000) break; // 연속한 두 수 제곱의 차가 g의 최댓값을 넘어서면 종료
    }

    if(ans.size()==0) cout<<-1;
    else{
        for(int i=0; i<ans.size(); i++) cout<<ans[i]<<'\n';
    }
}
