#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
 * 조건에 의해 최소 한개의 모음, 두개의 자음이 있어야 한다
 * cstw는 모음이 없으므로 안된다.
 */

const int SIZE = 15;
int l,c;
vector<char> alpa;
char ans[SIZE];
bool vowel[26]; //모음 체크할 배열
int vowel_cnt=0; //모음 갯수 카운트 할 변수

void backtracking(int index, int start){
    if(index == l && vowel_cnt>=1 && (index-vowel_cnt) >=2){
        for(int i=0; i<index; i++)
           cout<<ans[i];
        cout<<'\n';
        return;
    }

    for(int i = start; i<alpa.size(); i++){
        ans[index]=alpa[i];
        if(vowel[alpa[i] - 'a']){
            vowel_cnt++;
            backtracking(index+1, i+1);
            vowel_cnt--;
        }
        else backtracking(index+1, i+1);
    }

}

int main(){
    cin>>l>>c; // C개 중 L개의 알파벳을 택해서 암호 생성
    int temp = c;
    while(temp--){
        char i;
        cin>>i;
        alpa.push_back(i);
    }
    sort(alpa.begin(), alpa.end());

    //모음은 true로 변경
    vowel['a' - 'a'] = true;
    vowel['e' - 'a'] = true;
    vowel['i' - 'a'] = true;
    vowel['o' - 'a'] = true;
    vowel['u' - 'a'] = true;

    backtracking(0, 0);
}
