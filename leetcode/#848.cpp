class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        if(s.empty())
            return "";
         
        for(int i = shifts.size() - 2; i >= 0; i--){
            shifts[i] = (shifts[i] + shifts[i+1]) % 26;
        }

        for(int i=0;i<s.size();i++){
            int tmp = s[i] - 'a';
            tmp = (tmp + shifts[i]) % 26;
            s[i] = char(tmp + 'a');
            
        }
        
        return s;
    }
};