//
// Created by Zeno on 2020/4/13.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool judge(const vector<int> &arr, int i)
{
    for (int j = 0; j < i; ++j)
    {
        if (i == j || arr[i] == arr[j] || abs(arr[i] - arr[j]) == abs(i - j))
            return false;
    }
    return true;
}

void func(vector<int> &arr, int i, int length)
{
    if (i == length)
    {
        for (int j = 0; j < length; j++)
        {
            cout << arr[j] << ' ';
        }
        cout << endl;
    }
    else
    {
        for (int k = i; k < length; ++k)
        {
            swap(arr[i], arr[k]);
            if (judge(arr, i))
                func(arr, i + 1, length);
            swap(arr[i], arr[k]);
        }
    }
}

int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8}; // 该数组下标为棋盘行号，下标对应数值为棋盘列号
    func(arr, 0, arr.size());
    return 0;
}