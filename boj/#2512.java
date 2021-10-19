import java.util.*;

public class Main {

    static int[] cities = new int[10001];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N, M;

        N = sc.nextInt();

        int l = 0, r = 0;
        for(int i = 0; i<N;i++){
            cities[i] = sc.nextInt();
            r = Math.max(r, cities[i]);
        }

        M = sc.nextInt();
        int ans = 0;
        while(l <= r){
            int mid = (l+r) / 2;
            long sum = 0;

            for(int i = 0 ;i<N;i++){
                if(cities[i] <= mid){
                    sum += cities[i];
                }
                else{
                    sum += mid;
                }
            }

            if(sum <= M){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        System.out.println(ans);
    }
}
