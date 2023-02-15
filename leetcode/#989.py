class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        ans, tmp = [], 0
        for i in num:
            tmp = tmp * 10 + i
        k += tmp
        
        while k != 0:
            elem = k % 10
            ans = [elem] + ans
            k //= 10
 
        return ans