class Solution(object):
    def minPartitions(self, n):
        """
        :type n: str
        :rtype: int
        """
        ans = 0
        for ch in n:
            ans = max(ans, int(ch))
            
        return ans