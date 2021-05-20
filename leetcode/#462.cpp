// nums.size 가 홀수, 짝수 일때로 경우를 나누었지만, Median을 이용해도 상관 없다.

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;
        
        int ans = 0;
        int target = 0;
        sort(nums.begin(), nums.end());
        
        if(nums.size() % 2 != 0)
            target = nums[nums.size()/2];
        else
            target = (nums[nums.size()/2] + nums[(nums.size()/2)-1])/2;
        
        
        for(int i = 0;i<nums.size();i++){
            ans += abs(nums[i] - target);
        }
        
        return ans;
    }
};