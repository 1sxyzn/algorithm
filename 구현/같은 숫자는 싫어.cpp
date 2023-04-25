#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer(1,0);
    answer[0] = arr[0];
    for(int i=1; i<arr.size(); i++){
        if(arr[i]!=arr[i-1]) answer.push_back(arr[i]);
    }
    return answer;
}
