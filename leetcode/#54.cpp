// space complexity O(N^2)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));

        bool flag = true;
        int i = 0, j = 0;

        while (flag) {
            flag = false;

            // right
            while (j < matrix[i].size() && !visited[i][j]) {
                visited[i][j] = true;
                answer.push_back(matrix[i][j]);
                j++; flag = true;
            }
            j--; i++;

            // down
            while (i < matrix.size() && !visited[i][j]) {
                visited[i][j] = true;
                answer.push_back(matrix[i][j]);
                i++; flag = true;
            }
            i--; j--;

            // left
            while (j >= 0 && !visited[i][j]) {
                visited[i][j] = true;
                answer.push_back(matrix[i][j]);
                j--; flag = true;
            }
            j++; i--;

            // up
            while (i >= 0 && !visited[i][j]) {
                visited[i][j] = true;
                answer.push_back(matrix[i][j]);
                i--; flag = true;
            }
            i++; j++;
        }

        return answer;
    }
};

// space complexity O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     
            
        if(matrix.size() == 0 && matrix[0].size() == 0 )
            return {};
        
        
        int row =0;
        int col =0; 
        int top =0; 
        int left =0; 
        int right = matrix[0].size()-1;
        int  bottom = matrix.size()-1;
        
        vector<int> result;
    
        
        
        while(top <= bottom && left <= right)
        {
            
         
            col = left;
            while(col <= right)
            {
                result.push_back(matrix[top][col]);
                col++;
            }
            top++;
            
            row = top;
         
            
            while(row <= bottom)
            {
                result.push_back(matrix[row][right]);
                row++;
            }
            right--;
            
           
            
            
          if(top <= bottom) // corner case only 1 row left
          {
            col = right;
            
            while(col >= left)
            {
                result.push_back(matrix[bottom][col]);
                col--;
            }
            
            bottom--;
            
          }
            
            
            if(left <= right) // corner case only 1 colmn left
            {
            
            row = bottom;
         
            
            while(row >= top)
            {
                result.push_back(matrix[row][left]);
                row--;
            }
            left++;
        }
            
        }
        
        return result;
    }
};