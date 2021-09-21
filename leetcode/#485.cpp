class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cons = 0, ans = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                cons++;
                ans = max(ans, cons);
            }
            else
                cons = 0;
        }
        
        return ans;
    }
};