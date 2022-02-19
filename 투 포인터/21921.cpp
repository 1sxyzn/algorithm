#include<iostream>
#include<vector>

using namespace std;

//슬라이딩 윈도우 이용
pair<int, int> blog(int n, int x, vector<int> visitor){
    //슬라이딩 윈도우 초기화 (맨 처음 데이터)
    int sum=0;
    for(int i=0; i<x; i++){ //첫날부터 x날까지의 누적 방문객
        sum+=visitor[i];
    }
    int ans = sum; //누적 방문객 수
    int count = 1; //경우의 수 = 1가지

    //슬라이딩 윈도우
    for(int i=x; i<n; i++){
        // x=3이라고 가정하면 위에서는 1일차, 2일차, 3일차 방문객의 합을 구함.
        // 이제 2일차, 3일차, 4일차의 합을 구해야 하므로
        // 아까 구한 누적합에서 1일차의 방문객 수를 뺀 뒤, 4일차의 방문객 수를 더한다.
        sum-=visitor[i-x];
        sum+=visitor[i];
        if(sum>ans) { //새로 구한 합이, 이전에 구한 합보다 크다면
            ans=sum; //ans 값 갱신
            count=1; //경우의 수 = 1가지
        }
        else if(sum==ans) //만약 새로 구한 값이 이전의 최댓값과 같다면
            count++; //경우의 수 + 1
    }
    return make_pair(ans, count);
}

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> visitor(n,0);
    for(int i=0; i<n; i++){
        cin>>visitor[i];
    }
    pair<int,int> ans = blog(n, x, visitor);

    if(ans.first==0)
        cout<<"SAD\n";
    else
        cout<<ans.first<<'\n'<<ans.second<<'\n';
}
