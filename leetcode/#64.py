class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        answer = 0

        
        H, W = len(grid), len(grid[0])
        
        for i in range(1, H):
            grid[i][0] += grid[i - 1][0]
        for i in range(1, W):
            grid[0][i] += grid[0][i-1]
        for i, j in product(range(1, H),range(1, W)):
            grid[i][j] += min(grid[i-1][j], grid[i][j-1])

        return grid[H - 1][W - 1]