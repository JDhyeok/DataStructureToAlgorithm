import java.util.*;

public class Main {

    final static Scanner sc = new Scanner(System.in);
    static boolean[] selfNums = new boolean[10001];

    public static void main(String[] args) {
        for(int i = 0 ; i < 10001; i++)
            selfNums[i] = true;

        checkSelfNum();

        for(int i = 1; i < 10001; i++){
            if(selfNums[i])
                System.out.println(i);
        }
    }

    static void checkSelfNum(){
        for(int i = 1; i < 10000; i++){
            int tmp = i, sum = 0;

            while(tmp != 0){
                sum += tmp % 10;
                tmp /= 10;
            }
            if(i + sum > 10000)
                continue;
            selfNums[i + sum] = false;
        }
    }
}
