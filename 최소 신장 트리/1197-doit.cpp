#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

vector<int> parent;

int find_parent(int a){
    if(a==parent[a]) return a;
    else return parent[a]= find_parent(parent[a]);

}

void union_set(int a, int b){
    a=find_parent(a);
    b=find_parent(b);
    if(a!=b) parent[b]=a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>>q;
    parent.assign(n+1,0);

    for(int i=0; i<=n; i++){
        parent[i]=i;
    }

    while(m--){
        int s,e,w;
        cin>>s>>e>>w;
        q.push({w,s,e});
    }

    int ans=0;
    int edge=0; // 엣지 몇개 사용했는지. n개 이상이면 사이클 발생
    while(edge<n-1){
        int s=get<1>(q.top());
        int e=get<2>(q.top());
        int w=get<0>(q.top());
        q.pop();

        if(find_parent(s)!=find_parent(e)){ // 두 노드의 부모가 다르면 연결해도 괜찮음. 같은 경우 연결하면 사이클 발생
            union_set(s,e);
            ans+=w;
            edge++;
        }
    }
    cout<<ans;
}
