//
// Created by Zeno on 2020/4/18.
//
#include <iostream>
#include <vector>

using namespace std;

#if 0
int minimumTotal(vector<vector<int>>& triangle) {
    // corner case
    if (triangle.size() == 0 || triangle[0].size() == 0){
        return 0;
    }

    int m = triangle.size();

    vector<vector<int>> dp(m, vector<int>(triangle[m - 1].size(), 0));
    dp[0][0] = triangle[0][0];

    for (int i = 1; i < m; ++i){
        int n = triangle[i].size();
        for (int j = 0; j < n; ++j){
            if (j == 0){
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            }
            else if (j == n - 1){
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            }
            else{
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
        }
    }
    // 打印dp数组
    for (int i = 0; i < m; ++i){
        int n = triangle[i].size();
        for (int j = 0; j < n; ++j){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }

    int res = INT_MAX;
    for (int i = 0; i < triangle[m - 1].size(); ++i){
        res = min(res, dp[m - 1][i]);
    }
    return res;
}
#endif

int minimumTotal(vector<vector<int>>& triangle) {
    // corner case
    if (triangle.size() == 0 || triangle[0].size() == 0){
        return 0;
    }

    int m = triangle.size();

    vector<int> dp(m, 0);
    dp[0] = triangle[0][0];
    int prev = 0;
    int cur = 0;

    for (int i = 1; i < m; ++i){
        int n = triangle[i].size();
        for (int j = 0; j < n; ++j){
            cur = dp[j];
            if (j == 0){
                dp[j] = cur + triangle[i][j];
            }
            else if (j == n - 1){
                dp[j] = prev + triangle[i][j];
            }
            else{
                dp[j] = min(prev, cur) + triangle[i][j];
            }
            prev = cur;
        }
    }
    // 打印dp数组
    for (int i = 0; i < triangle[m - 1].size(); ++i){
        cout << dp[i] << ' ';
    }
    cout << endl;
    int res = INT_MAX;
    for (int i = 0; i < triangle[m - 1].size(); ++i){
        res = min(res, dp[i]);
    }
    return res;
}

int main(){
    vector<vector<int>> v{
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}
    };
    cout << minimumTotal(v) << endl;
    return 0;
}