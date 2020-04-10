//
// Created by Zeno on 2020/4/10.
//

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> nums;
        for (int i = 1; i <= N; i++)
        {
            nums.push_back(i);
        }

        divide(nums, 0, N -1);
        return nums;
    }
private:
    void divide(vector<int> &nums, int left, int right)
    {
        if (right - left <= 1)
        {
            return;
        }

        int mid = (left + right) / 2;
        vector<int> odd, even;
        for (int i = left; i <= right; i++)
        {
            if ((i + 1 - left) & 1)
            {
                odd.push_back(nums[i]);
            }
            else
            {
                even.push_back(nums[i]);
            }
        }

        std::copy(odd.begin(), odd.end(), nums.begin() + left);
        std::copy(even.begin(), even.end(), nums.begin() + left + odd.size());

        divide(nums, left, mid);
        divide(nums, mid + 1, right);
    }
};