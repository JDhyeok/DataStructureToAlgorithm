class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        row, col =   len(matrix)-1, 0        # <-- start at corner

        while row >=0 and col <= len(matrix[0])-1:  
            val = matrix[row][col]
            
            if val > target:
                row-= 1
            elif val < target:
                col+= 1
            else: return True
            
        return  False
#         O(N^2)
#         for i in range(len(matrix)):
#             for j in range(len(matrix[i])):
#                 if matrix[i][j] == target:
#                     return True
                
#         return False
            