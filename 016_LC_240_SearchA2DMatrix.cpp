//
// Created by Zeno on 2020/4/11.
//

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }
        int max_row = matrix.size() - 1;
        int max_column = matrix[0].size() - 1;
        int row = 0;
        int column = max_column;

        while (row <= max_row && column >= 0)
        {
            int cur = matrix[row][column];
            if (cur == target)
            {
                return true;
            }
            else if (cur > target)
            {
                column--;
            }
            else
            {
                row++;
            }
        }

        return false;
    }
};