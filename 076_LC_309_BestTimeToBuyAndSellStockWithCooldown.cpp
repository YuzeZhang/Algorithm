//
// Created by Zeno on 2020/5/6.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // base case
        // dp_i_0 means maxProfit in ith day and keeping no stock now
        // dp_i_1 means maxProfit in ith day and keeping stock now
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        // prev_dp_i_0 means maxProfit in (i-2)th day and keeping no stock now
        int prev_dp_i_0 = 0;
        for (int i = 0; i < n; i++) {
            // temp and prev_dp_i_0 are used to record the maxProfit in (i-2)th day (the day before yesterday)
            int temp = dp_i_0;
            // if you don't have stock today, that means you don't have stock yesterday either, or you sell it today
            dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);
            // if you have stock today, that means you have stock yesterday too, or you sell it the day before yesterday
            dp_i_1 = std::max(dp_i_1, prev_dp_i_0 - prices[i]);
            prev_dp_i_0 = temp;
        }
        return dp_i_0;
    }
};