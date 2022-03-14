class Solution(object):
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        cur, prev, ans = 1, 0, 0
        
        for i in range(1, len(s)):
            if s[i] == s[i-1]: cur += 1
            else:
                ans += min(prev, cur) 
                prev = cur
                cur = 1
                
        return ans + min(prev, cur)