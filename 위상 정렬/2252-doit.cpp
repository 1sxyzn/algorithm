#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>student(n+1,vector<int>(0));
    vector<int>indegree(n + 1, 0);

    while(m--){
        int a,b;
        cin>>a>>b;
        student[a].push_back(b);
        indegree[b]++;
    }

    queue<int>q;
    for(int i=1; i<=n; i++){
        if(indegree[i]==0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        cout<<node<<' ';
        q.pop();
        for(int i=0; i<student[node].size(); i++){
            indegree[student[node][i]]--;
            if(indegree[student[node][i]]==0) q.push(student[node][i]);
        }
    }
}
