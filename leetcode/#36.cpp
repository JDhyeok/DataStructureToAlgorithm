class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int length = board[0].size();
        int mask = 0;
        
        // check valid of row
        for(int i = 0; i < length; i++){
            mask &= 0;
            for(int j = 0; j < length; j++){
                if('0' <= board[i][j] && '9' >= board[i][j]){
                    
                    if(((1 << int(board[i][j] - '0')) & mask) > 0)
                        return false;
                    
                    mask |= (1 << int(board[i][j] - '0'));
                }
            }
        }
        
        // check valid of column
        for(int i = 0; i < length; i++){
            mask &= 0;
            for(int j = 0; j < length; j++){
                if('0' <= board[j][i] && '9' >= board[j][i]){
                    if(((1 << int(board[j][i] - '0')) & mask) > 0)
                        return false;
                    
                    mask |= (1 << int(board[j][i] - '0'));
                }
            }
        }
        
        int BOX[9][2] = {{0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2} };
        
        // check valid of 3x3 box
        for(int i = 0; i < length; i+=3){
            mask &= 0;
            
            for(int j = 0; j < length; j+=3){
                mask &= 0;
                for(int b = 0; b < 9; b++){
                    int ni = i + BOX[b][0];
                    int nj = j + BOX[b][1];
                    
                    if('0' <= board[ni][nj] && '9' >= board[ni][nj]){
                        if(((1 << int(board[ni][nj] - '0')) & mask) > 0)
                            return false;
                    
                        mask |= (1 << int(board[ni][nj] - '0'));
                    }
                }
            }
        }
        
        return true;
    }
};