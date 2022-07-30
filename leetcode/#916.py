class Solution(object):
    def wordSubsets(self, words1, words2):
        """
        :type words1: List[str]
        :type words2: List[str]
        :rtype: List[str]
        """
        
        max_freq = {}
        
        for word in words2:
            tmp = {}
            for ch in word:
                tmp[ch] = tmp.get(ch, 0) + 1
            
            for k, v in tmp.items():
                if max_freq.get(k) == None:
                    max_freq[k] = v
                else:
                    max_freq[k] = max(max_freq[k], v)
        
        ans = []
        
        for word in words1:
            flag = True
            tmp = {}
            for ch in word:
                tmp[ch] = tmp.get(ch, 0) + 1
            
            for k, v in max_freq.items():
                if tmp.get(k) == None or tmp[k] < v:
                    flag = False
                    break
            if flag == True:
                ans.append(word)
                
        return ans