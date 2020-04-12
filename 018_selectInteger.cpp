//
// Created by Zeno on 2020/4/12.
//
#include <iostream>
#include <vector>

using namespace std;

// 整数选择问题：给定2n个整数，从里面挑出n个整数，让选择的整数的和，和剩下的总数的和的差最小


int arr[] = {12, 6, 7, 11, 16, 3, 8};
const int length = sizeof(arr) / sizeof(arr[0]);

vector<int> x; // 子集辅助数组，记录被包含的节点
vector<int> bestX; // 记录差值最小的子集，也就是答案
int min = INT_MAX; // 记录差值的最小值，用于比较
int sum = 0; // 所选择的整数的和
int r = 0; // 剩下的整数的和

void func(int i)
{
    if (i == length)
    {
        int ret = abs(sum - r);
        if (ret < min)
        {
            min = ret;
            bestX = x;
        }
    }
    else
    {
        r -= arr[i];
        sum += arr[i];
        x.push_back(arr[i]);
        func(i + 1);

        sum -= arr[i];
        r += arr[i];
        x.pop_back();
        func(i + 1);
    }
}
