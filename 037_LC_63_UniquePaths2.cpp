//
// Created by Zeno on 2020/4/17.
//

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1)
            return 0;

        obstacleGrid[0][0] = 1;
        for (int i = 1; i < n; ++i){
            if (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1){
                obstacleGrid[0][i] = 1;
            }else{
                obstacleGrid[0][i] = 0;
            }
        }
        for (int i = 1; i < m; ++i){
            if (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1){
                obstacleGrid[i][0] = 1;
            }else{
                obstacleGrid[i][0] = 0;
            }
        }
        long res[m][n];
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                res[i][j] = obstacleGrid[i][j];
            }
        }
        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                if (res[i][j] != 1){
                    res[i][j] = res[i - 1][j] + res[i][j - 1];
                }else{
                    res[i][j] = 0;
                }
            }
        }

        return res[m - 1][n - 1];
    }
};