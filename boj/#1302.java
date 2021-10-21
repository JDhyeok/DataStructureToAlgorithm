import java.io.*;
import java.util.*;

public class Main {


    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        HashMap<String, Integer> hashMap = new HashMap<String, Integer>();
        String ans = "";
        int max = 0;

        for(int i = 0 ;i < N; i++){
            String tmp = br.readLine();

            if(!hashMap.containsKey(tmp)){
                hashMap.put(tmp, 1);
            }else{
                hashMap.put(tmp, hashMap.get(tmp) + 1);
            }
        }

        for(String key : hashMap.keySet()){
            int cnt = hashMap.get(key);

            if(max == cnt && ans.compareTo(key) > 0){
                ans = key;
                max = cnt;
            }
            else if(max < cnt){
                ans = key;
                max = cnt;
            }
        }

        System.out.println(ans);
    }
}
