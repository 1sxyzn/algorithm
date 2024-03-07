import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        if(arr.length == 1) {
            int[] answer = {-1};
            return answer;
        }
        
        List<Integer> ar = new ArrayList<>();
        for(int i=0;i<arr.length; i++){
            ar.add(arr[i]);
        }
        int[] filter = arr;
        Arrays.sort(filter);
        int min = filter[0];
        ar.remove(Integer.valueOf(min));
        
        int[] answer = ar.stream().mapToInt(i -> i).toArray();
        return answer;
    }
}