#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<char, pair<char,char>>tree;

void inorder(char node){
    if(node =='.') return;
    inorder(tree[node].first);
    cout<<node;
    inorder(tree[node].second);
}

void preorder(char node){
    if(node =='.') return;
    cout<<node;
    preorder(tree[node].first);
    preorder(tree[node].second);
}

void postorder(char node){
    if(node =='.') return;
    postorder(tree[node].first);
    postorder(tree[node].second);
    cout<<node;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    char root, left, right;
    while(n--){
        cin>>root>>left>>right;
        tree[root]={left, right};
    }

    preorder('A'); cout<<'\n';
    inorder('A'); cout<<'\n';
    postorder('A'); cout<<'\n';
}
