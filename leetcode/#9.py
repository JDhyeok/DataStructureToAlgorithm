class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        
        origin_num = x
        reversed_num = 0
        
        while x:
            tmp = int(x % 10)
            reversed_num = reversed_num * 10 + tmp
            x //= 10
        
        return origin_num == reversed_num