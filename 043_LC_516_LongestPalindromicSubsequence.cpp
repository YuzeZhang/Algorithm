//
// Created by Zeno on 2020/4/20.
//

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.size() == 0){
            return 0;
        }

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // initialize
        for (int i = 0; i < n; i++){
            dp[i][i] = 1;
        }

        for (int i = n - 2; i >= 0; i--){
            for (int j = i + 1; j < n; j++){
                if (s[i] == s[j]){
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }else{
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};