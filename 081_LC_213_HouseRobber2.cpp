//
// Created by Zeno on 2020/5/7.
//

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        // "the first house is the neighbor of the last one" means:
        // can't rob the first one and the last one together
        // so we can rob [0, n - 2] or [1, n - 1]
        return std::max(robRange(nums, 0, n - 2),
                        robRange(nums, 1, n - 1));
    }
    int robRange(vector<int>& nums, int start, int end) {
        int n = nums.size();
        int dp_i_1 = 0, dp_i_2 = 0;
        int dp_i = 0;
        for (int i = end; i >= start; i--) {
            dp_i = std::max(dp_i_1, dp_i_2 + nums[i]);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};