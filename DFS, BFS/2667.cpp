#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};

vector<string> house;
vector<int>ans;
int n;
int cnt;

void dfs(int i, int j){

    cnt++;
    for(int k=0; k<4; k++){
        if(i+dx[k]<n && j+dy[k]<n && i+dx[k]>=0 && j+dy[k]>=0 && house[i+dx[k]][j+dy[k]]!='0') {
            house[i+dx[k]][j+dy[k]]='0';
            dfs(i+dx[k], j+dy[k]);
        }
    }
}

int main(){
    cin>>n;
    house.assign(n," ");
    for(int i=0; i<n; i++){
        cin>>house[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(house[i][j]!='0') {
                cnt=0;
                house[i][j]='0';
                dfs(i, j);
                ans.push_back(cnt);
            }
        }
    }
    cout<<ans.size()<<'\n';

    sort(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<'\n';
    }
}
