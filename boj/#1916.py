import heapq
from collections import defaultdict

def dijkstra(v):
    pq = []

    heapq.heappush(pq, (0, v))
    dist[v] = 0

    while len(pq) != 0:
        cost, cur_v = heapq.heappop(pq)

        if dist[cur_v] < cost:
            continue

        for element in adj_list[cur_v]:
            next_v, next_cost = element[0], element[1] + cost

            if next_cost < dist[next_v]:
                dist[next_v] = next_cost
                heapq.heappush(pq, (next_cost, next_v))

N = int(input())
M = int(input())

dist = [987654321]*(N + 1)

adj_list = defaultdict(list)

for _ in range(M):
    x, y, cost = list(map(int, input().split()))
    adj_list[x].append([y, cost])

strt, dest = list(map(int, input().split()))

dijkstra(strt)

print(dist[dest])