//
// Created by Zeno on 2020/4/28.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int size = s.size();
    if (size == 0 || size == 1) {
        return size;
    }
    int *position = new int[26];
    for (int i = 0; i < 26; i++) {
        position[i] = -1;
    }
    vector<int> dp(size, 0);
    int maxLength = 0;

    dp[0] = 1;
    int ch = s[0] - 'a';
    position[ch] = 0;
    for (int i = 1; i < size; i++) {
        ch = s[i] - 'a';
        if (position[ch] == -1) {
            dp[i] = dp[i - 1] + 1;
        } else {
            int distance = i - position[ch];
            if (distance <= dp[i - 1]) {
                dp[i] = distance;
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }
        position[ch] = i;
        maxLength = std::max(maxLength, dp[i]);
    }
    delete[] position;
    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}