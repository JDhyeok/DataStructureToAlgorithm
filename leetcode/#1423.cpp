class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(cardPoints.empty())
            return 0;
        
        int sum = 0; 
        for (size_t i = 0; i < k; ++i) {
            sum += cardPoints[i];
        }
        
        int MAX = sum;
        for(int i = 0; i < k;i++){
            sum -= cardPoints[k-i-1];
            sum += cardPoints[cardPoints.size()-i-1];
            MAX = max(MAX, sum);
        }
        
        return MAX;
    }
};
