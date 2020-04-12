//
// Created by Zeno on 2020/4/12.
//

#include <iostream>
#include <vector>

using namespace std;

// 子集树代码
void func(int arr[], int i, int length, int x[])
{
    if (i == length) // 递归结束的条件
    {
        for (int j = 0; j < length; ++j)
        {
            if (x[j] == 1)
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
    else
    {
        x[i] = 1; // 选择i节点
        func(arr, i + 1, length, x); // 遍历i的左孩子

        x[i] = 0; // 不选择i节点
        func(arr, i + 1, length, x); // 遍历i的右孩子
    }
}
