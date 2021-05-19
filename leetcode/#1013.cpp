class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        
        for(int i = 0; i<arr.size();i++)
            sum += arr[i];
        
        if(sum % 3 != 0)
            return false;
        
        int target = sum / 3;
        
        bool firstFound = false, secondFound = false, thirdFound = false;
        
        int prefixSum = 0;
        for(int i = 0; i < arr.size();i++){
            
            prefixSum += arr[i];
            
            if(!firstFound && target == prefixSum){
                firstFound = true;
            }
            else if(firstFound && !secondFound && target*2 == prefixSum){
                secondFound = true;
            }
            else if(firstFound && secondFound && target*3 == prefixSum){
                thirdFound = true;
            }
        }

        return (firstFound && secondFound && thirdFound);
    }
};