# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        l, r = 0, n
        ret = n
        
        while l <= r:
            
            mid = int((l + r) / 2)
            
            if isBadVersion(mid) == True:
                r = mid - 1
                ret = min(ret, mid)
            elif isBadVersion(mid) == False:
                l = mid + 1
                
        return ret