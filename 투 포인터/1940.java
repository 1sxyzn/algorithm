import java.util.*;

public class N007 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr = new int[n];
        int p1=0;
        int p2=n-1;
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        int ans = 0;
        Arrays.sort(arr);
        while(p1<p2){
            if(arr[p1] + arr[p2] == m){
                ans++;
                p1++;
                p2--;
            }
            else if(arr[p1] + arr[p2] < m) p1++;
            else p2--;
        }
        System.out.println(ans);
    }
}
