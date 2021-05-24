class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ret;
        vector<string> pal;
        
        if(s.empty())
            return ret;
        
        dfs(0, s, pal, ret);
        
        return ret;
    }
    
    void dfs(int idx, string& s, vector<string>& pal, vector<vector<string>>& ret){
        if(idx == s.size()){
            ret.push_back(pal);
            return;
        }
        
        for(int i = idx ; i<s.size() ;i++){
            if(isPalindrome(s, idx, i)){
                pal.push_back(s.substr(idx, i - idx + 1));
                dfs(i+1, s, pal, ret);
                pal.pop_back();
            }
        }
        
    }
    
    bool isPalindrome(string& subString, int start, int end){

        while(start <= end){
            if(subString[start++] != subString[end--])
                return false;
        }
        return true;
    }
};