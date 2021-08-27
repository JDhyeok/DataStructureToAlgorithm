class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.size() == 1 && preorder[0] == '#')
            return true;
        

        stack<pair<int, int>> s;
        string tmp;
        int idx = 0;

        for (int i = 0; i < preorder.size(); i++) {
            if ('0' <= preorder[i] && preorder[i] <= '9') {
                tmp = "";
                while ('0' <= preorder[i] && preorder[i] <= '9') {
                    tmp += preorder[i];
                    i++;
                }
                if (!s.empty()) {
                    s.top().second--;

                    if (s.top().second == 0)
                        s.pop();
                }
                s.push(make_pair(stoi(tmp), 2));

            }
            else if (preorder[i] == '#') {
                if (s.empty())
                    return false;
                s.top().second--;
                if (s.top().second == 0)
                    s.pop();
                
                if(s.empty() && i < preorder.size() - 2)
                    return false;
            }
            else
                continue;
        }

        return !s.size();
    }
};


// space complexity: O(N)       time complexity: O(N)
bool isValidSerialization(const string& preorder)
{   
    int capacity = 1; 
     
    istringstream in(preorder); 
     
    string node; 
    while (getline(in, node, ','))
    {
        capacity -= 1;

        if (capacity < 0)
        {
            return false; 
        }

        if (node != "#")
        {   
            capacity += 2;
        }
    }
    
    return capacity == 0; 
}    