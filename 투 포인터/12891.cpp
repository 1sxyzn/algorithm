#include<iostream>
#include<vector>

using namespace std;

vector<int>check(4,0); //필요한 알파벳 갯수 입력
vector<int>cur(4,0); //현재 알파벳 갯수 저장

void add(char c){ // cur 배열에 해당 char 갯수 저장
    if(c=='A') cur[0]++;
    else if(c=='C') cur[1]++;
    else if(c=='G') cur[2]++;
    else cur[3]++;
}

void remove(char c){
    if(c=='A') cur[0]--;
    else if(c=='C') cur[1]--;
    else if(c=='G') cur[2]--;
    else cur[3]--;
}

bool verify(){
    for(int i=0; i<4; i++){
        if(check[i]>cur[i]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int answer=0;
    int s,p; // 문자열 길이, 부분 문자열 길이
    cin>>s>>p;

    //문자열 입력
    string dna;
    cin>>dna;

    for(int i=0; i<4; i++){ // 차례대로 {‘A’, ‘C’, ‘G’, ‘T’}
        cin>>check[i];
    }

    // 첫번째 윈도우 생성
    for(int i=0; i<p; i++){
        add(dna[i]);
    }
    if(verify()) answer++; // 첫번째 윈도우 검증

    //반복 돌며 윈도우 이동
    for(int i=p; i<s; i++){
        add(dna[i]);
        remove(dna[i-p]);
        if(verify()) answer++;
    }

    cout<<answer;
}
