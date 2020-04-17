//
// Created by Zeno on 2020/4/17.
//

class Solution {
public:
    //dp[i] = dp[i - 1] + dp[i - 2]
    int climbStairs(int n) {
        int stepOne = 1;
        int stepTwo = 0;
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res = stepOne + stepTwo;
            stepTwo = stepOne;
            stepOne = res;
        }
        return res;
    }
};