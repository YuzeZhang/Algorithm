//
// Created by Zeno on 2020/4/14.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void backtracking(vector<vector<int>> &res, vector<int> &cur, int n, int k, int index)
    {
        if (cur.size() == k)
        {
            res.push_back(cur);
            return;
        }
        else
        {
            for (int i = index; i <= n; i++)
            {
                cur.push_back(i);
                backtracking(res, cur, n, k, i + 1);
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        // Corner case
        if (n == 0 || k == 0)
            return vector<vector<int>>();

        // General case
        vector<vector<int>> res;
        vector<int> cur;
        backtracking(res, cur, n, k, 1);
        return res;
    }
};

int main()
{
    Solution sl;
    vector<vector<int>> res = sl.combine(1, 1);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}