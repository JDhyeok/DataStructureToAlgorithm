import java.util.*;

public class Main {

    public static class Edge implements Comparable<Edge>{
        int a, b, cost;

        public Edge(int a, int b, int cost){
            this.a=a;
            this.b=b;
            this.cost=cost;
        }

        // Priority Queue에서 우선순위 정할 수 있도록 해주는 @override 메소드
        @Override
        public int compareTo(Edge e){
            return this.cost - e.cost;
        }
    }


    static int[] parent = new int[10001];
    static int[] ranks = new int[10001];

    static int find(int x){
        if(parent[x] == x)
            return x;

        int y = find(parent[x]);
        parent[x] = y;
        return y;
    }

    static boolean merge(int a, int b){
        int x = find(a);
        int y = find(b);

        if(x == y)
            return false;

        if(ranks[x] < ranks[y]){
            parent[y] = x;
            ranks[x] += ranks[y];
        }else{
            parent[x] = y;
            ranks[y] += ranks[x];
        }
        return true;
    }

    static void init(){
        for(int i = 0 ;i < 10001; i++){
            parent[i] = i;
            ranks[i] = 1;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        init();

        int V, E;
        PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
        V = sc.nextInt();
        E = sc.nextInt();

        int a, b, c;
        for(int i = 0 ; i < E;i++){
            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();

            pq.add(new Edge(a, b, c));
        }
        int ans = 0;

        // kruskal 진행
        while(!pq.isEmpty()){
            Edge cur = pq.poll();

            if(merge(cur.a, cur.b)){
                ans += cur.cost;
            }
        }

        System.out.println(ans);
    }
}
