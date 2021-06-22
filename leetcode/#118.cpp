class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        
        for(int row=1;row<=numRows;row++){
            ans[row-1].resize(row);
            ans[row-1][0]=1;
            for(int col=1; col<row-1;col++){
                ans[row-1][col]=ans[row-2][col-1]+ans[row-2][col]; 
            }
            ans[row-1][row-1]=1;
        }
        return ans;
    }
};