//
// Created by Zeno on 2020/5/2.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_map<char, int> count_char; // count_char.second records the next position of char which has came up, then if we find the repeating char, we can move left to count_char[s[right]]
        int res = 0;

        while (right < s.size()) {
            if (count_char.count(s[right])) {
                left = std::max(left, count_char[s[right]]);
            }
            count_char[s[right]] = right + 1;
            res = std::max(right - left + 1, res);
            right++;
        }
        return res;
    }
};