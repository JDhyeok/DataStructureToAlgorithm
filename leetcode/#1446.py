class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        
        ret, q = 0, deque()
        visited = [False] * (n + 1)

        q.append(0)
        visited[0] = True

        # negative : 0 => 1 역방향
        # positive : 1 => 0 정방향
        negative_adj_list, positive_adj_list = defaultdict(list), defaultdict(list)

        for connect in connections:
            negative_adj_list[connect[0]].append(connect[1])
            positive_adj_list[connect[1]].append(connect[0])

        while len(q) != 0:
            cur = q.popleft()

            if len(negative_adj_list[cur]) != 0:
                for nxt in negative_adj_list[cur]:
                    if visited[nxt] == False:
                        ret += 1
                        visited[nxt] = True
                        q.append(nxt)

            if len(positive_adj_list[cur]) != 0:
                for nxt in positive_adj_list[cur]:
                    if visited[nxt] == False:
                        visited[nxt] = True
                        q.append(nxt)

        return ret