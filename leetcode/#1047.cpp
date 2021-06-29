// inplace & O(n^2)
class Solution {
public:
    string removeDuplicates(string s) {

        bool flag = true;
        
        while (1) {
            flag = true;
            
            for (int i = 0; i < s.size() - 1;) {
                if (s.empty())
                    break;
                if (s[i] == s[i + 1]) {
                    s.erase(i, 2);
                    flag = false;
                    continue;
                }
                i++;
            }
            
            if (flag == true)
                break;
        }
        return s;
    }
};

// not inplace & O(n)
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        int i(0);

        while(i< s.length()) {
            if( res.length() == 0){
                res.push_back(s[i++]);
                continue;
            }
            else if( s[i] == res.back()){
                i++;
                res.pop_back();
            }
            else{
                res.push_back(s[i++]);
            }
        } 
        return res;
    }
};