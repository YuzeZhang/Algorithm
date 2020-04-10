//
// Created by Zeno on 2020/4/10.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority_element = nums[0], count = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (majority_element == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }

            if (count == 0)
            {
                majority_element = nums[i];
                count++;
            }
        }

        return majority_element;
    }
};