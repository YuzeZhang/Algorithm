//
// Created by Zeno on 2020/5/6.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // base case
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        // dp_i_0 means maxProfit in ith day and keeping no stock now
        // dp_i_1 means maxProfit in ith day and keeping stock now

        for (int i = 0; i < n; i++) {
            int temp = dp_i_0;
            // if you have stock today, that means you have stock yesterday too, or you buy it today
            dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);
            // if you don't have stock today, that means you don't have stock yesterday either, or you sell it today
            dp_i_1 = std::max(dp_i_1, temp - prices[i]);
        }

        return dp_i_0;
    }
};