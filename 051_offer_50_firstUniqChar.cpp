//
// Created by Zeno on 2020/4/24.
//

class Solution {
public:
    int status = 1;
    char res = ' ';
    char firstUniqChar(string s) {
        if (s.size() == 0){
            status = -1;
            return res;
        }
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++){
            if (mp[s[i]] == 1){
                res = s[i];
                return res;
            }
        }
        return res;
    }
};