//
// Created by Zeno on 2020/4/20.
//

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (0 == nums.size()){
            return 0;
        }
        vector<int> dp(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        int res = INT_MIN;
        for (int i = 0; i < dp.size(); i++){
            res = std::max(dp[i], res);
        }

        return res;
    }
};