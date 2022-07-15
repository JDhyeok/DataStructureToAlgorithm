class Solution(object):
    def countIsland(self, strt_i, strt_j, grid):
        
        dir = [[0,1], [1,0], [-1,0], [0,-1]]
        q, ret = [], 1
        
        q.append([strt_i, strt_j])
        grid[strt_i][strt_j] = 0
        
        while len(q) != 0:
            cur_i, cur_j = q[-1][0], q[-1][1]
            q.pop()
            
            for d in dir:
                next_i, next_j = cur_i + d[0], cur_j + d[1]
                if next_i < 0 or next_j < 0 or next_i >= len(grid) or next_j >= len(grid[0]):
                    continue    
                
                if grid[next_i][next_j] == 1:
                    q.append([next_i, next_j])
                    grid[next_i][next_j] = 0
                    ret += 1
        
        return ret
    
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ans = 0
        
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    ans = max(ans, self.countIsland(i, j, grid))
                    
        return ans