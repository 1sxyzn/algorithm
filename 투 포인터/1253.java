import java.util.*;

public class N008 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        int ans = 0;
        for(int i=0; i<n; i++) {
            int p1=0, p2=n-1;
            while(p1<p2){
                long sum = arr[p1]+arr[p2];
                if(sum==arr[i]){
                    if(p1!=i && p2!=i){
                        ans++;
                        break;
                    }
                    else if(p1==i) p1++;
                    else p2--;
                }
                else if(sum<arr[i]) p1++;
                else p2--;
            }
        }
        System.out.println(ans);
    }
}
