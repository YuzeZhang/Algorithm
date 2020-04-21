//
// Created by Zeno on 2020/4/21.
//

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

        return helper(K, N, dp);
    }
private:
    int helper(int K, int N, vector<vector<int>> dp){
        if (K == 1){
            dp[K][N] = N;
            return N;
        }
        if (N == 0){
            dp[K][N] = 0;
            return 0;
        }
        if (dp[K][N] != 0){
            return dp[K][N];
        }
        int res = INT_MAX;

        /*
        //Time Limit Exceeded
        for (int i = 1; i <= N; i++){
            res = std::min(res, std::max(helper(K - 1, i - 1, dp), helper(K, N - i, dp)) + 1);
        }
        */

        int low = 1;
        int high = N;
        while (low <= high){
            int mid = (low + high) / 2;
            int broken = helper(K - 1, mid - 1, dp);
            int notBroken = helper(K, N - mid, dp);
            if (broken > notBroken){
                res = min(res, broken + 1);
                high = mid - 1;
            }else{
                res = min(res, notBroken + 1);
                low = mid + 1;
            }
        }

        dp[K][N] = res;
        return res;
    }
};

class Solution {
public:
    int superEggDrop(int K, int N) {
        // dp[k][n] = m,当前有k个鸡蛋，可以尝试扔m次鸡蛋
        // m最多不会超过N次，当m==N时属于线性扫描
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
        int m = 0;
        while (dp[K][m] < N){
            m++;
            for (int i = 1; i <= K; i++){
                dp[i][m] = dp[i][m - 1] + dp[i - 1][m - 1] + 1;
            }
        }
        return m;
    }
};