//
// Created by Zeno on 2020/4/10.
//

class Solution {
public:
    bool error = false;
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
        {
            error = true;
            return -1;
        }

        int largest_sum = nums[0];
        int cur_sum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (cur_sum <= 0)
            {
                cur_sum = nums[i];
            }
            else
            {
                cur_sum += nums[i];
            }

            if (cur_sum > largest_sum)
            {
                largest_sum = cur_sum;
            }
        }

        return largest_sum;
    }
};