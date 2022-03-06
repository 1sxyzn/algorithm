#include <iostream>
#include <map>

using namespace std;

map<char,pair<int, int>> tree;

//전위 순회
void preorder(char c){
    if(c=='.')
        return;
    cout<<c;
    preorder(tree[c].first);
    preorder(tree[c].second);
}

//중위 순회
void inorder(char c){
    if(c=='.')
        return;
    inorder(tree[c].first);
    cout<<c;
    inorder(tree[c].second);
}

//후위 순회
void postorder(char c){
    if(c=='.')
        return;
    postorder(tree[c].first);
    postorder(tree[c].second);
    cout<<c;
}

int main(){
    int n;
    char root, left, right;
    cin>>n;
    while(n--){
        cin>>root>>left>>right;
        tree[root].first=left;
        tree[root].second=right;
    }

    //전위 순회
    preorder('A');
    cout<<'\n';

    //중중위 순회
    inorder('A');
    cout<<'\n';

    //후위 순회
    postorder('A');
    cout<<'\n';

}
