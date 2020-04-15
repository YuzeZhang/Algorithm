//
// Created by Zeno on 2020/4/14.
//

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        length = nums.size();
        visited.resize(length, false);
        backtracking(nums);
        return res;
    }
private:
    int length = 0;
    vector<vector<int>> res;
    vector<int> cur;
    vector<bool> visited;

    void backtracking(vector<int> &nums)
    {
        if (cur.size() == length)
        {
            res.push_back(cur);
            return;
        }
        else
        {
            for (int i = 0; i < nums.size(); i++){
                if (visited[i])
                    continue;
                if (i != 0 && !visited[i - 1] && nums[i] == nums[i - 1])
                    continue;
                visited[i] = true;
                cur.push_back(nums[i]);
                backtracking(nums);
                visited[i] = false;
                cur.pop_back();
            }

        }
    }
};