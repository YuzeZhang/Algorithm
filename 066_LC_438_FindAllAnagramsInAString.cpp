//
// Created by Zeno on 2020/5/2.
//

// use sliding window to solve this problem
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> window; // record the number of char in string p between left and right
        unordered_map<char, int> needs;
        for (char c : p) {
            needs[c]++;
        }
        int left = 0;
        int right = 0;
        int match = 0; // count the number of char whose number in window and needs is equal

        // move right to very right, if s[right] is in sting p, put it into window
        // if match == needs.size(), that means the substr from left to right include all elements in string p
        // then move left to right, if right - left == p.size(), that means the substr is a p's anagram
        while (right < s.size()) {
            char c1 = s[right];
            if (needs.count(c1)) {
                window[c1]++;
                if (window[c1] == needs[c1])
                    match++;
            }

            right++;

            while (match == needs.size()) {
                char c2 = s[left];
                if (right - left == p.size()) {
                    res.push_back(left);
                }
                if (window.count(c2)) {
                    window[c2]--;
                    if (window[c2] < needs[c2])
                        match--;
                }
                left++;
            }
        }

        return res;
    }
};