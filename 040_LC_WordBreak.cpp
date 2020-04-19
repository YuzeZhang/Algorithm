//
// Created by Zeno on 2020/4/19.
//

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        // dp[i]表示0~i的字串是否在字典中
        vector<bool> dp(len + 1, false);

        // 将字典用set存储
        unordered_set<string> wordSet;
        for (int i = 0; i < wordDict.size(); i++){
            wordSet.insert(wordDict[i]);
        }

        // 初始化成true因为
        dp[0] = true;

        for (int i = 1; i <= len; i++){
            for (int j = 0; j < i; j++){
                if (dp[j] == true && wordSet.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};