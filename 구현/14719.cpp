#include <iostream>
#include <vector>

using namespace std;

int main(){
    int h, w;
    cin>>h>>w;
    vector<int>block(w,0);
    for(int i=0; i<w; i++) cin>>block[i];

    vector<int> max_left(w,0);
    vector<int> max_right(w,0);
    for(int i=1; i<w; i++) max_left[i] = max(max_left[i-1], block[i-1]);
    for(int i=w-2; i>=0; i--) max_right[i] = max(max_right[i+1], block[i+1]);

    int ans = 0;
    for(int i=1; i<w-1; i++){
        ans += max(0, min(max_left[i], max_right[i]) - block[i]);
    }

    cout<<ans;
}
