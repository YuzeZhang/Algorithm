//
// Created by Zeno on 2020/5/2.
//

class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0; // record the beginning of the minium substring
        int minLen = INT_MAX;
        int left = 0, right = 0;
        int match = 0; // record the match number between window and needs

        unordered_map<char, int> window;
        unordered_map<char, int> needs;
        for (char c : t) {
            needs[c]++;
        }

        // first, move right to very right
        // if match == needs.size(), move left to right until match < needs.size()
        while (right < s.size()) {
            char c1 = s[right];
            if (needs.count(c1)) {
                window[c1]++;
                if (window[c1] == needs[c1]) {
                    match++;
                }
            }
            right++;

            while (match == needs.size()) {
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if (needs.count(c2)) {
                    window[c2]--;
                    if (window[c2] < needs[c2])
                        match--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};