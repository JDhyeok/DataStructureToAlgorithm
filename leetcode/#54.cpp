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