#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    int m, v;
    cin>>n>>k;
    vector<pair<int,int>>gem;
    vector<int>bag(k,0);
    for(int i=0; i<n; i++){
        cin>>m>>v;
        gem.push_back({m,v});
    }
    sort(gem.begin(), gem.end());

    long long ans = 0;
    for(int i=0; i<k; i++){
        cin>>bag[i];
    }
    sort(bag.begin(), bag.end());

    /*
    오름차순으로 정렬된, i번째 가방에 담을 수 있는 보석을 무게가 작은 순으로 z개 와다닥 담고, 가치가 가장 큰 값 pop
    그리고 보석은 무게 순으로 되어 있으니, pop한 다음에는 i+1 번째 가방에 담을 수 있는 보석을 z+1 부터 와다닥 담기
    (~z 번째는 이미 담겨 있으니 z+1 번째 부터 담으면 됨.
    만약 내용물을 초기화하고 처음부터 z+1 번째 까지 다시 담은 뒤, 가치가 가장 큰 값 꺼내려고 하면 시간 초과!)
    */

    int j=0;
    priority_queue<int>pq; // 가치와 인덱스 저장
    for(int i=0; i<k; i++){
        while(j < n && gem[j].first <= bag[i]){
            pq.push(gem[j].second);
            j++;
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    cout<<ans;
}
