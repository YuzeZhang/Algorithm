//
// Created by Zeno on 2020/5/5.
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // base case
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        // dp_i_0: the ith day's maxProfit, 0 means keeping no stock now
        // dp_i_1: the ith day's maxProfit, 1 means keeping stock now

        for (int i = 0; i < n; i++) {
            // if you don't have stock today, that means you don't have stock yesterday either, or you sell the stock on today
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            // if you keep stock today, that means you kept stock yesterday either, or you buy the stock on today
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;
    }
};