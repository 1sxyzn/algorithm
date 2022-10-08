#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<bool>visit(10001,false);
    for(int i=1; i<10001; i++){
        int k=i;
        int num=i;
        while(k!=0){
            num+=k%10;
            k/=10;
        }
        visit[num]=true;
    }

    for(int i=1; i<10001; i++){
        if(!visit[i]) cout<<i<<'\n';
    }
}
