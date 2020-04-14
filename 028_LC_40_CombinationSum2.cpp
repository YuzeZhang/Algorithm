//
// Created by Zeno on 2020/4/14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> cur;
    void backtracking(vector<int> &cand, int target, int index)
    {
        if (target < 0)
            return;
        else if (target == 0)
        {
            res.push_back(cur);
            return;
        }
        else if (cand[index] > target)
            return;

        for (int i = index; i < cand.size(); i++)
        {
            cur.push_back(cand[i]);
            backtracking(cand, target - cand[i], i + 1);
            while (i + 1 < cand.size() && cand[i + 1] == cand[i])
                i++;
            cur.pop_back();
        }
    }
};

int main()
{
    vector<int> v{2, 2, 2};
    Solution sl;
    vector<vector<int>> res = sl.combinationSum2(v, 2);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}