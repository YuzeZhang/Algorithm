//
// Created by Zeno on 2020/4/10.
//

class Solution {
public:
    int countSum(int left, int right, int mid)
    {
        int largest_sum1 = INT_MIN, largest_sum2 = INT_MIN;
        int cur_sum1 = 0, cur_sum2 = 0;

        for (int i = mid; i >= left; i--)
        {
            cur_sum1 += arr[i];
            largest_sum1 = max(largest_sum1, cur_sum1);
        }

        for (int i = mid + 1; i <= right; i++)
        {
            cur_sum2 += arr[i];
            largest_sum2 = max(largest_sum2, cur_sum2);
        }

        return largest_sum1 + largest_sum2;
    }
    int helper(int left, int right)
    {
        if (left >= right)
        {
            return arr[left];
        }

        int mid = (left + right) / 2;
        int sumLeft = helper(left, mid);
        int sumRight = helper(mid + 1, right);

        int sum = countSum(left, right, mid);

        return max(sum, max(sumLeft, sumRight));
    }
    int maxSubArray(vector<int>& nums) {
        arr = nums;
        return helper(0, nums.size() - 1);
    }
private:
    vector<int> arr;
};