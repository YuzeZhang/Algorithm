//
// Created by Zeno on 2020/4/27.
//

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> res(T.size(), 0);
        for (int i = T.size() - 1; i >= 0; i--){
            while (!s.empty() && T[s.top()] <= T[i]){
                s.pop();
            }
            res[i] = s.empty() ? 0 : s.top() - i;
            s.push(i);
        }
        return res;
    }
};