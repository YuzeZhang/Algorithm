//
// Created by Zeno on 2020/4/27.
//

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, 0);
        stack<int> s;

        for (int i = size * 2 - 1; i >= 0; i--){
            while (!s.empty() && s.top() <= nums[i % size]){
                s.pop();
            }
            res[i % size] = s.empty() ? -1 : s.top();
            s.push(nums[i % size]);
        }
        return res;
    }
};