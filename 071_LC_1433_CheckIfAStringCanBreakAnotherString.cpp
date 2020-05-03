//
// Created by Zeno on 2020/5/3.
//

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());

        bool res1 = true;
        bool res2 = true;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] < s2[i]) {
                res1 = false;
            }
            if (s1[i] > s2[i]) {
                res2 = false;
            }
        }
        return res1 || res2;
    }
};