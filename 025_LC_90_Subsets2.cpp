//
// Created by Zeno on 2020/4/14.
//

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        length = nums.size();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return ret;
    }
private:
    vector<vector<int>> ret;
    vector<int> temp;
    int length;
    int tail = INT_MIN;


    void backtracking(const vector<int> &nums, int i)
    {
        ret.push_back(temp);
        if (i < length)
        {
            for (int j = i; j < length; ++j)
            {
                if (tail == nums[j])
                    continue;
                temp.push_back(nums[j]);
                backtracking(nums, j + 1);
                tail = temp[temp.size() - 1];
                temp.pop_back();
            }
        }
    }
};

// 解法2
class Solution {
public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        _length = nums.size();
        sort(nums.begin(), nums.end());
        helper(nums, 0);
        return _ret;
    }
private:
    int _length;
    int _tail = INT_MIN;
    vector<int> _curSubsets;
    vector<vector<int>> _ret;

    void helper(const vector<int> &nums, int i)
    {
        if (i == _length)
        {
            _ret.push_back(_curSubsets);
        }
        else
        {
            _curSubsets.push_back(nums[i]);
            if (nums[i] != _tail)
                helper(nums, i + 1);
            _tail = _curSubsets[_curSubsets.size() - 1];
            _curSubsets.pop_back();

            helper(nums, i + 1);
        }
    }
};