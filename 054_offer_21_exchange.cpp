//
// Created by Zeno on 2020/4/25.
//

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int size = nums.size();
        if (size == 0){
            return nums;
        }
        int i = 0;
        int j = size - 1;
        while (i < j){
            while (i < j && nums[i] % 2 != 0){
                i++;
            }
            while (i < j && nums[j] % 2 == 0){
                j--;
            }
            if (i < j){
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};