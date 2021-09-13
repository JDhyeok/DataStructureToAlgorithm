// My code
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        if(text.size() < 7)
            return 0;
        string balloon = "balloon";
        unordered_map<char, int> hashs;
        
        for(auto c : text){
            hashs[c]++;
        }
        int ans = 987654321;
        for(auto c : balloon){
            if(c == 'l' || c == 'o'){
                ans = min(ans, int(hashs[c]/2));
            }
            else
                ans = min(ans, hashs[c]);
        }
        
        return ans;
    }
};

// A bit more efficient
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        for (auto ch : text) {
            switch (ch) {
                case 'b':
                    b++; break;
                case 'a':
                    a++; break;
                case 'l':
                    l++; break;
                case 'o':
                    o++; break;
                case 'n':
                    n++; break;
            }
        }
        
        return min({b, a, l/2, o/2, n});
    }
};