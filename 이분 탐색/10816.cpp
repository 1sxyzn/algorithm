#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<int> card;

// 같은 숫자가 있다면, 그 수들을 가리키는 가장 작은 인덱스 반환
int lowerBound(int left, int right, int num){
    while(left<=right){ // left가 right를 넘어가는 순간 종료
        int mid = (left + right) /2 ;
        if(card[mid]>=num) //찾는 숫자랑 동일하면, 왼쪽에 같은 수가 더 있는지 확인해보자
            right = mid -1;
        else
            left = mid +1;
    }
    return right + 1;
    //  arr[mid]가 찾는 수와 같을 때, 이 위치보다 왼쪽에 같은 수가 있는지 확인했는데, 이때...
    // right = mid -1을 했으므로... 왼쪽에 같은 수가 없으면 mid 값, 즉 right + 1이 lowerBound 이다
}

// 같은 숫자가 있다면, 그 수들을 가리키는 가장 큰 인덱스 + 1 의 값 반환
int upperBound(int left, int right, int num){
    while(left<=right){
        int mid = (left + right) /2;
        if(card[mid] > num)
            right = mid -1;
        else // 찾는 수와 같거나 더 작은 수를 탐색 중이었다면...
        //1. 찾는 수와 동일한 수 였으면 오른쪽에 같은 수가 있는지 찾아야함
        //2. 더 작은 수를 탐색 중이었다면, mid값보다 크다는 의미이니 left를 mid보다 큰 값으로 설정
            left = mid +1;
    }
    return right + 1;
    //현재 right값은 해당 수의 가장 뒷 번호 index를 가리킴. upperBound는 그 index + 1 값이니 right +1...
    //left가 right를 벗어나는 순간 while이 종료되므로 right + 1 은 곧 left와도 같다. return left 해도됨
}

int main(){
    //입출력향상. 없으면 시간초과
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    card.assign(n,0);
    for(int i=0; i<n; i++)
        cin>>card[i];

    sort(card.begin(), card.end()); // 이분 탐색 정렬 필수!!

    int m, temp;
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>temp;
        cout<<upperBound(0, n-1, temp)- lowerBound(0, n-1, temp)<<' ';
    }
}
