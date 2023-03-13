#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

vector<int>parent;

int find_parent(int a){
    if(parent[a]==a) return a;
    else return parent[a]= find_parent(parent[a]);
}

void union_set(int a, int b){
    a= find_parent(a);
    b= find_parent(b);
    if(a!=b) parent[b]=a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>>q;

    int sum=0;
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(int j=0; j<s.length(); j++){
            int w=0;
            if(s[j]>= 'a' && s[j]<='z') w=s[j]-'a'+1;
            else if(s[j]>= 'A' && s[j]<='Z') w=s[j]-'A'+27;
            sum+=w; // 랜선 총 길이 합
            if(i!=j && w!=0) q.push({w,i,j});
        }
    }

    parent.assign(n,0);
    for(int i=0; i<n; i++) parent[i]=i;

    int edge=0;
    int ans=0;

    while(!q.empty()){
        int w=get<0>(q.top());
        int s=get<1>(q.top());
        int e=get<2>(q.top());
        q.pop();

        if(find_parent(s)!= find_parent(e)){
            union_set(s,e);
            ans+=w;
            edge++;
        }
    }
    if(edge==n-1) cout<<sum-ans;
    else cout<<-1;
}
