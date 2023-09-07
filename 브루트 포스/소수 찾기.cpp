#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    vector<bool>prime(10000000,true);
    prime[0] = prime[1] = false;
    for(int i=2; i*i<10000000; i++){
        for(int j=i+i; j<10000000; j+=i){
            prime[j] = false;
        }
    }
    
    map<int,int> m;
    for(int i=0; i<numbers.length(); i++){
        m[numbers[i]-'0']++;
    }
    
    for(int i=2; i<10000000; i++){
        map<int,int> temp = m;
        if(prime[i]){
            int num = i;
            bool flag = true;
            while(num>0){
                if(temp[num%10]>0){
                    temp[num%10]--;
                    num/=10;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag) answer++;
        }
        
    }
    return answer;
}
