//
// Created by Zeno on 2020/4/9.
//

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int left, int right, int mid)
{
    vector<int> tmp;
    tmp.reserve(right - left + 1);

    int i = left, j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j])
        {
            tmp.push_back(v[i++]);
        }
        else
        {
            tmp.push_back(v[j++]);
        }
    }

    while (i <= mid)
    {
        tmp.push_back(v[i++]);
    }
    while (j <= right)
    {
        tmp.push_back(v[j++]);
    }

    for (int k = left; k <= right; k++)
    {
        v[k] = tmp[k - left];
    }

}

void mergeSort(vector<int> &v, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;
    // 划分子问题
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);

    // 合并
    merge(v, left, right, mid);
}

int main()
{
    vector<int> v;
    for (int i = 0; i < 11; i++)
    {
        v.push_back(rand() % 100);
    }

    mergeSort(v, 0, v.size() - 1);

    for (auto num : v)
    {
        cout << num << ' ';
    }
    return 0;
}
