//
// Created by Zeno on 2020/4/20.
//

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), 0));
        return helper(word1.size() - 1, word2.size() - 1, word1, word2, memo);
    }
private:
    int helper(int i, int j, const string &word1, const string &word2, vector<vector<int>> &memo){
        if (i == -1){
            return j + 1;
        }
        if (j == -1){
            return i + 1;
        }

        if (memo[i][j] != 0){
            return memo[i][j];
        }

        if (word1[i] == word2[j]){
            memo[i][j] = helper(i - 1, j - 1, word1, word2, memo);
            return memo[i][j];
        }else {
            // Insert a character
            int resInsert = helper(i, j - 1, word1, word2, memo) + 1;
            // Delete a character
            int resDelete = helper(i - 1, j, word1, word2, memo) + 1;
            // Replace a character
            int resReplace = helper(i - 1, j - 1, word1, word2, memo) + 1;

            memo[i][j] = std::min({resInsert, resDelete, resReplace});
            return memo[i][j];
        }
    }
};