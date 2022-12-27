from collections import defaultdict
import heapq

def dijkstra():

    distance = [987654321] * (V + 1)
    distance[K] = 0
    q = []

    heapq.heappush(q, [0, K])

    while len(q) != 0:
        cur_cost, cur_vertex = heapq.heappop(q)

        if distance[cur_vertex] < cur_cost:
            continue

        for cand in adj_list[cur_vertex]:
            next_cost, next_vertex = cur_cost + cand[0], cand[1]
            
            if distance[next_vertex] < next_cost:
                continue

            distance[next_vertex] = next_cost
            heapq.heappush(q, [next_cost, next_vertex])

    return distance

V, E = list(map(int, input().split()))
K = int(input())

adj_list = defaultdict(list)

for _ in range(E):
    a, b, cost = list(map(int, input().split()))
    adj_list[a].append([cost, b])



dist = dijkstra()
for idx in range(1, V + 1):
    print(dist[idx] if dist[idx] != 987654321 else 'INF')