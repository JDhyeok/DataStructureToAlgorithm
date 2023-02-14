class Solution:
    def addBinary(self, a: str, b: str) -> str:

        ans = ''
        a_idx, b_idx = len(a) - 1, len(b) - 1
        carry = 0

        while a_idx >= 0 or b_idx >= 0:
            sum = carry
            
            if a_idx >= 0:
                sum += int(a[a_idx])
            if b_idx >= 0:
                sum += int(b[b_idx])
            
            ans = str(sum % 2) + ans
            carry = sum // 2
            
            a_idx -= 1
            b_idx -= 1
        
        if carry != 0:
            ans = str(carry) + ans
        
        return ans