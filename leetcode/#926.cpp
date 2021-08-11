class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int tmp, ans = 987654321;
        int cnt = 0, zeros = 0, ones = 0;
        
        for(auto bin : s){
            if(bin == '0') zeros++;
            if(bin == '1') ones++;
        }
        
        for(auto bin : s){
            if(bin == '1'){
                tmp = min(zeros+cnt, ones+cnt);
                ans = min(ans, tmp);
                
                cnt++; ones--;
            }
            else if(bin == '0')
                zeros--;
        }
        if(ans == 987654321)
            ans = 0;
        
        return ans;
    }
};

// More Simple
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int counter_one = 0;
        int counter_flip = 0;
        
        for (auto ch : s) {
            if (ch == '1') {
                ++counter_one;
            } else {
                ++counter_flip;
            }
            counter_flip = smin(counter_one, counter_flip);
        }
        return counter_flip;
    }
};