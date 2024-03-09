import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = s.nextInt();
        }
        Arrays.sort(arr);

        for(int i=0; i<n; i++){
            System.out.println(arr[i]);
        }
    }
}
