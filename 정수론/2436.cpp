#include<iostream>
#include<cmath>

using namespace std;

/*
 최대공약수 G, 최소공배수 L
 G*L = A*B 이다. A = G*a, B=G*a이면
 (이때 a, b는 서로소. 왜냐하면 최대공약수 G를 끄집어 냈으므로)
 G*L = G*a*G*b이고 약분하면
 L/G=a*b가 된다.

 L G가 주어지니 이를 이용해서 A+B, 즉 a+b가 최소가 되는 a b를 찾고
 a b에 G를 구해 최종적으로 A, B를 찾자
 */

//유클리드 호제법
int gcd(int n, int m){
    while(m){
        int t=n%m;
        n=m;
        m=t;
    }
    return n;
}

int main(){
    int G, L;
    cin>>G>>L;

    int a,b;

    int ab= L/G;
    for(int i=sqrt(ab);i>0;i--){ // i*i = ab 에 가장 가까운 중간 값 i 구하기
        if(ab%i==0){ // a*b = ab가 되는 한 수를 찾음

            // a, b는 서로소라는 가정을 했으니, 서로소인지 확인
            // 두 수가 서로소라면 최대공약수 = 1
            if(gcd(ab/i,i)==1){
                a=i;
                b=ab/i;
                break;
            }
        }

    }
    cout<<a*G<<' '<<b*G<<'\n';
}
