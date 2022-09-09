class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:

        A = sorted(properties, key=lambda x:(-x[0],x[1]))
        max_num, ans = A[0][1], 0
        
        for i in range(len(A)):
            if max_num > A[i][1]:
                ans += 1
                
            max_num = max(max_num, A[i][1])
        
        return ans