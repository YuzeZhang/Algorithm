//
// Created by Zeno on 2020/4/14.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        backtracking(nums, target);
        return res;
    }
private:
    int res = 0;
    void backtracking(vector<int> &nums, int target)
    {
        if (target == 0)
        {
            res++;
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > target)
                break;

            backtracking(nums, target - nums[i]);
        }
    }
};

int main()
{
    vector<int> v{1, 2, 3};
    Solution sl;
    time_t begin = clock();
    int res = sl.combinationSum4(v, 32);
    time_t end = clock();

    cout << end - begin << "ms" << endl; //剪枝前:5000ms 181997601

    cout << res << endl;

    return 0;
}
