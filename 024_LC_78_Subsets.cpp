//
// Created by Zeno on 2020/4/14.
//

class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        length = nums.size();
        helper(nums, 0);
        return ret;
    }
private:
    int length;
    vector<int> curNums;
    vector<vector<int>> ret;
    void helper(vector<int> &nums, int i)
    {
        if (i == length)
        {
            ret.push_back(curNums);
        }
        else
        {
            curNums.push_back(nums[i]);
            helper(nums, i + 1);
            curNums.pop_back();

            helper(nums, i + 1);
        }
    }
};