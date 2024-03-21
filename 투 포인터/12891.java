import java.util.Scanner;

public class N009 {
    static int ans = 0;
    static int match = 0;
    static int[] arr = new int[4];
    static int[] cur = new int[4];

    static void add(char c){ // {‘A’, ‘C’, ‘G’, ‘T’}
        if(c=='A'){
            cur[0]++;
            if(arr[0]==cur[0]) match++;
        }
        else if(c=='C'){
            cur[1]++;
            if(arr[1]==cur[1]) match++;
        }
        else if(c=='G'){
            cur[2]++;
            if(arr[2]==cur[2]) match++;
        }
        else{
            cur[3]++;
            if(arr[3]==cur[3]) match++;
        }
    }

    static void del(char c){ // {‘A’, ‘C’, ‘G’, ‘T’}
        if(c=='A'){
            if(arr[0]==cur[0]) match--;
            cur[0]--;
        }
        else if(c=='C'){
            if(arr[1]==cur[1]) match--;
            cur[1]--;
        }
        else if(c=='G'){
            if(arr[2]==cur[2]) match--;
            cur[2]--;
        }
        else{
            if(arr[3]==cur[3]) match--;
            cur[3]--;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();

        String s = sc.nextLine();

        for(int i=0; i<4; i++) {
            arr[i] = sc.nextInt();
            if(arr[i]==0) match++;
        }
        for(int i=0; i<m; i++) add(s.charAt(i));
        if(match==4) ans++;

        for(int i=m; i<n; i++){
            add(s.charAt(i));
            del(s.charAt(i-m));
            if(match==4) ans++;
        }

        System.out.println(ans);
    }
}
