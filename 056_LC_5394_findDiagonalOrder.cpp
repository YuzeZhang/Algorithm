//
// Created by Zeno on 2020/4/26.
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#if 0
bool isExist(const vector<vector<int>> &nums, int i, int j) {
    if (i >= nums.size()) {
        return false;
    }
    if (j >= nums[i].size()) {
        return false;
    }
    return true;
}

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    vector<int> res;
    int m = nums.size();
    int n = INT_MIN;
    for (int i = 0; i < m; i++){
        n = max((int)nums[i].size(), n);
    }
    for (int k = 0; k < m; k++){
        for (int i = k, j = 0; i >= 0 && j < n; i--, j++){
            if (isExist(nums, i, j)){
                res.push_back(nums[i][j]);
            }
        }
    }

    for (int k = 1; k < n; k++){
        for (int i = m - 1, j = k; i >= 0 && j < n; i--, j++){
            if (isExist(nums, i, j)){
                res.push_back(nums[i][j]);
            }
        }
    }


    return res;
}
#endif

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    int m = nums.size();
    map<int, vector<int>> mp;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < nums[m].size(); j++){
            mp[i + j].push_back(nums[i][j]);
        }
    }
    vector<int> res;
    for (auto it : mp) {
        for (int i = it.second.size() - 1; i >= 0; i--){
            res.push_back(it.second[i]);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> v{{1,2,3}, {4,5,6}, {7,8,9}};
    vector<int> res = findDiagonalOrder(v);
    return 0;
}