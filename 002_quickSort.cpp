//
// Created by Zeno on 2020/4/8.
//

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int left, int right)
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
void quickSort(vector<int>& nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int pos = partition(nums, left, right);
    quickSort(nums, left, pos - 1);
    quickSort(nums, pos + 1, right);
}
vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
}
int main()
{
    vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(rand() % 100);
    }

    for(auto num : v)
    {
        cout << num << ' ';
    }

    quickSort(v, 0, v.size() - 1);
    cout << endl;
    cout << endl;

    for(auto num : v)
    {
        cout << num << ' ';
    }
    return 0;
}
