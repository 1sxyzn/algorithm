import java.util.*;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int[photo.length];
        Map<String, Integer> m = new HashMap<>();
        for(int i=0; i<yearning.length; i++){
            m.put(name[i], yearning[i]);
        }
        
        for(int i=0; i<photo.length; i++){
            for(int j=0; j<photo[i].length; j++){
                // getOrDefault : map에서 key에 해당하는 원하는 value가 있으면 가져오고, 없으면 설정한 default값을 가지고 옴
                answer[i] += m.getOrDefault(photo[i][j], 0);
            }
        }
        return answer;
    }
}