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