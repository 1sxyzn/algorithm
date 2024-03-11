import java.util.*;

public class N003 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr = new int[n+1];
        arr[0] = 0;
        for(int i=1; i<=n; i++){
            arr[i] = arr[i-1] + sc.nextInt();
        }

        int s, e;
        for(int i=0; i<m; i++){
            s = sc.nextInt();
            e = sc.nextInt();
            System.out.println(arr[e] - arr[s-1]);
        }
    }
}
