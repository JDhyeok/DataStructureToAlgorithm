class NumArray {
private:
    vector<int> arr;
    vector<int> dp;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        dp.push_back(sum);
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            dp.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return dp[right+1]-dp[left];
    }
};