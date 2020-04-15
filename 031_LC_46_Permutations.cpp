//
// Created by Zeno on 2020/4/14.
//

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        length = nums.size();
        vector<bool> state(length, false);
        backtracking(nums, state, 0);

        return res;
    }
private:
    int length = 0;
    vector<vector<int>> res;
    vector<int> cur;

    void backtracking(vector<int> &nums, vector<bool> &state, int index)
    {
        if (index == length)
        {
            res.push_back(cur);
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (!state[i])
                {
                    state[i] = true;
                    cur.push_back(nums[i]);
                    backtracking(nums, state, index + 1);
                    cur.pop_back();
                    state[i] = false;
                }
            }
        }
    }
};