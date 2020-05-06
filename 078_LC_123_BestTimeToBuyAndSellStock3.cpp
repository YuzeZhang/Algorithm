//
// Created by Zeno on 2020/5/6.
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

int maxProfit(vector<int>& prices) {
    int size = prices.size();
    int max_k = 2;
    //vector<vector<vector<int>>> dp(size, vector<vector<int>>(max_k + 1, vector<int>(2, 0)));
    int dp[size][max_k + 1][2];

    for (int i = 0; i < size; i++) {
        dp[i][0][0] = 0;
        dp[i][0][1] = INT_MIN;
    }
    for (int i = 0; i < size; i++) {
        for (int k = max_k; k >= 1; k--) {
            if (i - 1 == -1) {
                dp[i][k][0] = 0;
                dp[i][k][1] = INT_MIN;
                continue;
            }
            dp[i][k][0] = std::max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
            dp[i][k][1] = std::max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
        }
    }
    return dp[size - 1][max_k][0];
}

int main() {
    vector<int> v{1,2,3};
    cout << maxProfit(v) << endl;
    return 0;
}