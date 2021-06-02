// My Solution
class Solution {
public:
    
    int WAY[4][2] = { {0, 1}, {0, -1}, {1, 0},{-1, 0} };
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    int cnt = 1;
                    grid[i][j] = 0;
                    dfs(i, j, cnt, grid);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
    
    void dfs(int i, int j, int& cnt, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[i].size();
        
        for(int w = 0; w < 4; w++){
            int ni = i + WAY[w][0];
            int nj = j + WAY[w][1];
            
            if(ni >= m || nj >= n || ni < 0 || nj < 0){
                continue;
            }
            
            if(grid[ni][nj] == 1){
                grid[ni][nj] = 0;
                cnt += 1;
                dfs(ni, nj, cnt, grid);
            }
        }
    }
};


// Clearer Solution
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (grid[i][j] == 1) ans = max(ans, dfs(grid, i, j));
        return ans;
    }
private:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size(), area = 1;
        
        grid[row][col] = 2;
        
        vector<int> dir({-1,0,1,0,-1});
        
        for (int i = 0; i < 4; i++) {
            int r = row+dir[i], c = col+dir[i+1];
            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) 
                area += dfs(grid, r, c);
        }
        return area;
    }
};