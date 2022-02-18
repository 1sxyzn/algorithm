#include<iostream>
#include<map>

using namespace std;

// upper_bound : 해당 원소보다 큰 원소 중 가장 왼쪽에 있는 원소 -> 같은 값 미포함
// lower_bound : 해당 원소와 같거나 큰 원소 중 가장 왼쪽에 있는 원소 -> 같은 값 포함

int main(){
    //입출력 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> power;
    int n, m, max;
    string name;
    
    cin>>n>>m;
    while(n--){
        cin>>name>>max;
        if(power[max].empty()) //같은 상한값이 들어오면 먼저 들어온 것을 인식해야하므로
            power[max]=name; // if문을 통해 이후 같은 상한값이 들어온 것은 저장하지 않는다.
    }

    int i;
    while(m--){
        cin>>i;
        cout<<power.lower_bound(i)->second<<'\n';
    }
}
