import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N, C;

        N = sc.nextInt();
        C = sc.nextInt();

        int[] house = new int[N];

        for(int i = 0 ;i < N;i++){
            house[i] =sc.nextInt();
        }
        Arrays.sort(house);

        int l = 0, r = house[N-1]-house[0], d;
        int ans = 0;

        while(l <= r){
            int mid = (l + r)/2;
            int cnt = 1, strt = house[0];

            // 위치
            for(int i = 1; i < N; i++){
                d = house[i] - strt;
                if(mid <= d){
                    cnt++;
                    strt = house[i];
                }
            }
            
            // 공유기 설치를 모두 다 했다.
            if(cnt >= C){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        System.out.println(ans);
    }
}
