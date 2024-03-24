import java.util.*;

public class N011 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();

        int cnt = 1;
        boolean p = false;
        Stack<Integer> s = new Stack<>();
        ArrayList<Character> c = new ArrayList<>();
        for(int i=0; i<n; i++){
            if(arr[i]>=cnt){
                while(arr[i]>=cnt){
                    s.push(cnt);
                    cnt++;
                    c.add('+');
                }
                s.pop();
                c.add('-');
            }
            else{
                if(arr[i]<=s.peek()){
                    s.pop();
                    c.add('-');
                }
                else{
                    System.out.println("NO");
                    p = true;
                    break;
                }
            }
        }

        if(!p){
            for(int i=0; i<c.size(); i++){
                System.out.println(c.get(i));
            }
        }
    }
}
