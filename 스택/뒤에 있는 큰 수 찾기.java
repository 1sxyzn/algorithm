import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        Stack<Integer> s = new Stack<>();
        for(int i=0; i<numbers.length; i++){
            while(!s.empty() && numbers[s.peek()]<numbers[i]){
                answer[s.peek()] = numbers[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            answer[s.peek()] = -1;
            s.pop();
        }
        return answer;
    }
}
