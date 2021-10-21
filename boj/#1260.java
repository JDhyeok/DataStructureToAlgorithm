import java.io.*;
import java.util.*;

public class Main {

    static int N, M;
    static int[][] adjMat = new int[1001][1001];
    static boolean[] visited = new boolean[1001];

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);

        int V;

        for(int i = 0; i < 1001; i++)
            visited[i] = false;

        N = sc.nextInt();
        M = sc.nextInt();
        V = sc.nextInt();

        int a, b;
        for(int i = 0 ; i < M; i++){
            a = sc.nextInt();
            b = sc.nextInt();
            adjMat[a][b] = 1;
            adjMat[b][a] = 1;
        }
        dfs(V);
        for(int i = 0; i < 1001; i++)
            visited[i] = false;
        System.out.println();
        bfs(V);
    }

    static void dfs(int cur){
        System.out.print(cur);

        visited[cur] = true;
        for(int i = 1; i <= N; i++){
            if(adjMat[cur][i] == 1 && !visited[i]){
                System.out.print(" ");
                visited[i] = true;
                dfs(i);
            }
        }
    }

    static void bfs(int V){
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(V);
        visited[V] = true;

        while(!q.isEmpty()){
            int cur = q.poll();
            System.out.print(cur);
            for(int i = 1; i <= N; i++){
                if(adjMat[cur][i] == 1 && !visited[i]){
                    visited[i] = true;
                    q.add(i);
                }
            }
            System.out.print(" ");
        }
    }
}
