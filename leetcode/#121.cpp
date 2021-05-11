class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MAX = 0, MIN = 987654321;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < MIN)
                MIN = prices[i];
            if((prices[i]-MIN)>MAX)
                MAX = prices[i] - MIN;
        }
        return MAX;
    }
};