//
// Created by Zeno on 2020/5/6.
//

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string str1 = s.substr(0, n);
        string str2 = s.substr(n, s.size() - n);
        return str2 + str1;
    }
};