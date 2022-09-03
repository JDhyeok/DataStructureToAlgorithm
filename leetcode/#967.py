class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        
        global ans, num_str
        
        ans = []
        
        def dfs(cur, num_str, n, k):
            if len(num_str) == n:
                if num_str[0] == '0':
                    return                    
                ans.append(num_str)
                return
            
            num_str += str(cur)
            
            p_next = cur + k
            n_next = cur - k
            1
            if p_next < 10:
                dfs(p_next, num_str, n, k)
            if n_next >= 0:
                dfs(n_next, num_str, n, k)
        
        for i in range(1,10):
            dfs(i, '', n, k)
        
        return list(set(ans))