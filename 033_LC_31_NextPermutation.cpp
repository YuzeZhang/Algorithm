//
// Created by Zeno on 2020/4/15.
//

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = 0;
        for (i = nums.size() - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
                break;
        }
        sort(nums.begin() + i + 1, nums.end());
        for (int j = i; j < nums.size(); ++j)
        {
            if (nums[i] < nums[j])
            {
                swap(nums[i], nums[j]);
                return;
            }
        }
    }
};