#include<iostream>
#include<cmath>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3){ // ccw 계산
    // 그냥 x1 ~ y4를 처음부터 long long 으로 받는게 나을수도 .,,
    long long result = ((long long)x1*y2+(long long)x2*y3+(long long)x3*y1) - ((long long)x2*y1+(long long)x3*y2+(long long)x1*y3);
    if(result>0) return 1;
    else if(result<0) return -1;
    else return 0;
}

bool isOverLap(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){ // 겹치는지 확인
    if(min(x1,x2)<=max(x3,x4) && min(x3,x4)<=max(x1,x2) && min(y1,y2)<=max(y3,y4) && min(y3,y4)<=max(y1,y2)) return true;
    else return false;
}

bool isCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){ // 교차하는지 확인
    int abc = ccw(x1,y1,x2,y2,x3,y3);
    int abd = ccw(x1,y1,x2,y2,x4,y4);
    int cda = ccw(x3,y3,x4,y4,x1,y1);
    int cdb = ccw(x3,y3,x4,y4,x2,y2);

    if(abc*abd==0 && cda*cdb==0) return isOverLap(x1,y1,x2,y2,x3,y3,x4,y4); // 두 선분이 일직선일 경우, 겹치면 교차한다고 침
    else if(abc*abd<=0 && cda*cdb<=0) return true; // 일직선 아니고 교차하는 경우 (ab선분에 c와 d가 같은 방향에 있으면 안겹침, 다른 방향에 있으면 겹침)
    else return false;
}

int main(){
    int x1,x2,x3,x4,y1,y2,y3,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    bool cross = isCross(x1,y1,x2,y2,x3,y3,x4,y4);

    if(cross) cout<<1;
    else cout<<0;
}
