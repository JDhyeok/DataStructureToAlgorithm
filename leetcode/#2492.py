class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        ret = 987654321

        q = deque()
        dp = [987654321] * (n + 1)

        q.append(1)

        adj_list = [[] for _ in range(n + 1)]

        for road in roads:
            adj_list[road[0]].append([road[1], road[2]])
            adj_list[road[1]].append([road[0], road[2]])
        
        while len(q) != 0:
            cur = q.popleft()
            for adj in adj_list[cur]:
                if adj[1] < dp[adj[0]]:
                    dp[adj[0]] = adj[1]
                    q.append(adj[0])

        return min(dp)