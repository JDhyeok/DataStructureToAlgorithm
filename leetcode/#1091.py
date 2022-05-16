class Solution(object):
    
    def bfs(self, grid):
        DIR = [[1, 0], [0, 1], [-1, 0], [0, -1], [1, 1], [-1, 1], [-1, -1], [1, -1]]
        n = len(grid)
        
        q = deque()
        
        if grid[0][0] == 1:
            return -1
        
        grid[0][0] = 1
        q.append([0, 0, 0])
        
        while len(q) != 0:
            cur_i, cur_j, cur_cnt = q.popleft()
            
            if cur_i == n - 1 and cur_j == n - 1:
                return cur_cnt + 1
            
            for dir in DIR:
                next_i, next_j = cur_i + dir[0], cur_j + dir[1]
                
                if next_i < 0 or next_j < 0 or next_i >= n or next_j >= n:
                    continue
                if grid[next_i][next_j] == 1:
                    continue
                
                grid[next_i][next_j] = 1
                q.append([next_i, next_j, cur_cnt + 1])
        
        return -1
    
    def shortestPathBinaryMatrix(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        return self.bfs(grid)