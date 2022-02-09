#include<iostream>

using namespace std;

//짝수 승일 때 a의 b 승 = a의 b/2승 * a의 b/2 승
//홀수 승일 때 a의 b 승 = a * a의 (b-1) 승

// (a*b)%c = (a%c * b%c)%c 를 이용하여 overflow를 막자

//분할 정복
long long divide(int a, int b, int c){
    if(b==1) //기저조건, conquer
        return a % c;

    //divide = b가 짝수 or 홀수일 경우로 나누기
    if(b%2==0) { //짝수 승일 때
        long long sub = divide(a, b/2, c); //a의 b/2 승
        return sub * sub % c; //combine
    }
    //홀수 승일 때
    return a * divide(a, b-1, c) % c; //combine
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;

    cout<<divide(a, b, c) <<'\n';
}
