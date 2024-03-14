import java.util.*;

public class N006 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int p1 = 1;
        int p2 = 1;
        int sum = 1;
        int ans = 0;
        while(p2 < n){
            if(sum==n) {
                ans++;
                p2++;
                sum += p2;
            }
            else if(sum<n){
                p2++;
                sum += p2;
            }
            else {
                sum -= p1;
                p1++;
            }
        }
        System.out.println(ans+1);
    }
}
