//
// Created by Zeno on 2020/4/11.
//
#include <iostream>
#include <vector>

using  namespace std;


int partition(vector<int> &nums, int left, int right)
{
    int key = nums[left];
    while (left < right)
    {
        while (left < right && nums[right] >= key)
        {
            right--;
        }
        if (left < right)
        {
            nums[left++] = nums[right];
        }

        while (left < right && nums[left] < key)
        {
            left++;
        }
        if (left < right)
        {
            nums[right--] = nums[left];
        }
    }

    nums[left] = key;
    return left;
}
// 这个函数是用来求第k小的！！！！
int helper(vector<int> &nums, int left, int right, int k)
{
    if (left >= right)
    {
        return -1;
    }

    int pos = partition(nums, left, right);
    if (pos == k - 1)
    {
        return nums[pos];
    }
    else if (pos < k - 1)
    {
        return helper(nums, pos + 1, right, k);
    }
    else
    {
        return helper(nums, left, pos - 1, k);
    }
}
int findKthLargest(vector<int>& nums, int k) {
    return helper(nums, 0, nums.size() - 1, k);
}
int main()
{
    vector v{3,2,1};
    cout << findKthLargest(v, 5);
    return 0;

}