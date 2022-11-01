class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        
        ans = ''
        
        num1_idx, num2_idx = len(num1) - 1, len(num2) - 1
        tmp, carry = 0, 0
        
        while num1_idx >= 0 and num2_idx >= 0:
            
            tmp = int(num1[num1_idx]) + int(num2[num2_idx]) + carry
            
            carry = tmp // 10
            tmp = tmp % 10
            
            ans = str(tmp) + ans
            
            num1_idx -= 1
            num2_idx -= 1
        
        while num1_idx >= 0:
            tmp = int(num1[num1_idx]) + carry
            carry = tmp // 10
            tmp = tmp % 10
            ans = str(tmp) + ans
            num1_idx -= 1
            
        while num2_idx >= 0:
            tmp = int(num2[num2_idx]) + carry
            carry = tmp // 10
            tmp = tmp % 10
            ans = str(tmp) + ans
            num2_idx -= 1
        if carry > 0:
            ans = str(carry) + ans
            
        return ans