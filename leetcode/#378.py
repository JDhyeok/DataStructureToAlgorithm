class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        ans = []
        for i in range(len(matrix)):
            ans.extend(matrix[i])
            
        ans = sorted(ans)
        return ans[k - 1]