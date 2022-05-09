class Solution(object):
    
    def dfs(self, digits_dict, digits, cur, word, ans):
        
        if cur == len(digits):
            ans.append(word)
            return
        
        cur_num = int(digits[cur])
        
        for ch in digits_dict[cur_num]:
            word += ch
            self.dfs(digits_dict, digits, cur + 1, word, ans)
            word = word[:-1]
            
    
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if len(digits) == 0:
            return []
        
        ans = []
        digits_dict = {2: "abc", 3: "def", 4: "ghi", 5: "jkl", 6: "mno", 7: "pqrs", 8: "tuv", 9: "wxyz"}
        
        self.dfs(digits_dict, digits, 0, "", ans)
        
        return ans