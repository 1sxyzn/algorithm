#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    while(n--){
        int student, sum=0;
        cin>>student;
        vector<int> score(student,0);
        for(int i=0; i<student; i++){
            cin>>score[i];
            sum+=score[i];
        }
        double avg = (double)sum/student;
        int over=0;
        for(int i=0; i<student; i++){
            if(score[i]>avg) over++;
        }

        cout << fixed;
        cout.precision(3);
        cout<<(double)over/student*100<<"%\n";
    }
}
