// My First Solution
// 4ms 8.5MB
class Solution {
public:
    
    int countBit(int num){
        int ret = 0;
        while(num){
            if((num & 1) != 0)
                ret++;
            num = num >> 1;
        }
        return ret;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i = 0; i <= n; i++){
            ans.push_back(countBit(i));
        }
        
        return ans;
    }
};


// BEST SOLUTION
// 0ms, 7.9MB
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};