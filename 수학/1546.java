import java.util.*;

public class n002 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        int max = arr[arr.length-1];
        double ans = 0;
        for(int i=0; i<n; i++){
            ans += (double)arr[i]/max*100;
        }

        System.out.println(ans/n);
    }
}
