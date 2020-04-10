//
// Created by Zeno on 2020/4/10.
//

#include <vector>
#include <iostream>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int length1 = nums1.size();
    int length2 = nums2.size();
    if (length1 > length2)
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    if (length1 == 0)
    {
        int k = (length2 - 1) / 2;
        if (length2 % 2 == 0)
        {
            return (nums2[k] + nums2[k + 1]) * 1.0 / 2;
        }
        else
        {
            return nums2[k];
        }
    }

    int i = 0, j = 0, begin = 0, end = length1;
    int k = (length1 + length2 + 1) / 2;
    while (begin <= end)
    {
        i = (begin + end) / 2;
        j = k - i;
        if (i > 0 && j < length2 && nums1[i - 1] > nums2[j])
        {
            end = i - 1;
        }
        else if (j > 0 && i < length1 && nums2[j - 1] > nums1[i])
        {
            begin = i + 1;
        }
        else
        {
            // nums1[i - 1] < nums2[j] && nums2[j - 1] < nums1[i]
            break;
        }
    }

    int left = 0;
    if (i == 0)
    {
        left = nums2[j - 1];
    }
    else if (j == 0)
    {
        left = nums1[i - 1];
    }
    else
    {
        left = max(nums1[i - 1], nums2[j - 1]);
    }
    int right = 0;
    if (j == length2 - 1)
    {
        right = nums1[i];
    }
    else if (i == length1 - 1)
    {
        right = nums2[j];
    }
    else
    {
        right = min(nums1[i], nums2[j]);
    }

    if ((length1 + length2) % 2 == 0)
    {
        return (left + right) * 1.0 / 2;
    }
    else
    {
        return left * 1.0;
    }
}

int main()
{
    vector v1{1, 2, 3};
    vector v2{4};

    double ret = findMedianSortedArrays(v1, v2);

    cout << ret << endl;
    return 0;
}