//
// Created by Zeno on 2020/4/14.
//

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 0, 1);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> cur;
    void backtracking(int k, int n, int index, int i)
    {
        if (n < 0)
            return;
        if (index == k)
        {
            if (n == 0)
            {
                res.push_back(cur);
                return;
            }
            else
                return;
        }

        for (; i < 10; i++)
        {
            cur.push_back(i);
            backtracking(k, n - i, index + 1, i + 1);
            cur.pop_back();
        }
    }
};