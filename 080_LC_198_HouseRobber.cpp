//
// Created by Zeno on 2020/5/7.
//
#ifdef __LOCAL__
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <deque>
#else
#include<bits/stdc++.h>
#endif

using namespace std;

#if 0
class Solution {
public:
    int rob(vector<int>& nums) {
        memo = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            memo[i] = -1;
        }

    }
private:
    int *memo;
};
#endif

class Solution {
public:
    int rob(vector<int>& nums) {
        memo = new vector<int>(nums.size(), -1);
        return dp(nums, 0);
    }
private:
    vector<int> *memo;
    int dp(const vector<int>& nums, int start) {
        if (start >= nums.size()) {
            return 0;
        }

        if ((*memo)[start] != -1) {
            return (*memo)[start];
        }

        int res = std::max(dp(nums, start + 1), nums[start] + dp(nums, start + 2));
        (*memo)[start] = res;
        return res;
    }
};