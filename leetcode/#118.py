class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        ans = []
        
        for i in range(numRows):
            tmp = []
            for j in range(i + 1):
                if j == 0 or j == i:
                    tmp.append(1)
                else:
                    tmp.append(ans[i-1][j] + ans[i-1][j-1])
            ans.append(tmp)
            
        return ans