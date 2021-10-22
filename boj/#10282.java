import java.io.*;
import java.util.*;

public class Main {

    static int T, N, D, C;
    static int INF = 987654321;
    static int[] dist;

    static class Edge implements Comparable<Edge> {
        int v, cost;

        Edge(int v, int cost) {
            this.v = v;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge edge) {
            return this.cost - edge.cost;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;


        T = Integer.parseInt(br.readLine());

        while (T-- > 0) {

            st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken());
            D = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());

            ArrayList<Edge>[] adjList = new ArrayList[N + 1];
            dist = new int[N + 1];

            for(int i = 0; i <= N; i++)
                adjList[i] = new ArrayList<>();


            int a, b, c;

            for (int i = 0; i < D; i++) {
                st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                c = Integer.parseInt(st.nextToken());

                adjList[b].add(new Edge(a, c));
            }

            Arrays.fill(dist, Integer.MAX_VALUE);
            dijkstra(adjList, C);

            int cnt = 0, time = 0;

            for (int i = 1; i < dist.length; i++) {
                if (0 <= dist[i] && dist[i] < INF) {
                    cnt++;
                    if (time < dist[i])
                        time = dist[i];
                }
            }
            sb.append(cnt + " " + time + "\n");
        }
        System.out.println(sb);
    }

    static void dijkstra(ArrayList<Edge>[] adjList, int c) {

        PriorityQueue<Edge> pq = new PriorityQueue<Edge>();
        pq.add(new Edge(c, 0));
        dist[c] = 0;

        while(!pq.isEmpty()){
            Edge edge = pq.poll();
            int vertex = edge.v;
            int curCost = edge.cost;

            if(dist[vertex] < curCost)
                continue;

            for(int i = 0; i < adjList[vertex].size(); i++){
                int next = adjList[vertex].get(i).v;
                int nextCost = adjList[vertex].get(i).cost + curCost;

                if(dist[next] > nextCost){
                    dist[next] = nextCost;
                    pq.add(new Edge(next, nextCost));
                }
            }
        }
    }
}
