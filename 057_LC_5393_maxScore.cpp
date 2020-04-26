//
// Created by Zeno on 2020/4/26.
//

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxScore = 0;
        for (int i = 0; i < k; i++){
            maxScore += cardPoints[i];
        }
        int score = maxScore;
        for (int i = k - 1, j = cardPoints.size() - 1; i >= 0; i--, j--){
            score = score - cardPoints[i] + cardPoints[j];
            maxScore = std::max(score, maxScore);
        }
        return maxScore;
    }
};