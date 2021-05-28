class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> table;
        int answer = 0;
        for(auto word : words){
            int bit = 0;
            for(auto w : word){
                bit |= 1 << (w - 'a');
            }
            table[bit] = max(table[bit], (int)word.size());
        }
        
        for(auto a : table){
            for (auto b : table){
                if(!(a.first & b.first))
                    answer = max(answer, (a.second * b.second));
            }
        }
        return answer;
    }
};