#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<vector<int>>dist(n,vector<int>(n,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>dist[i][j];
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][k]==1 && dist[k][j]==1) dist[i][j]=1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dist[i][j]<<' ';
        }
        cout<<'\n';
    }
}
