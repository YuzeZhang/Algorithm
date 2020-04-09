//
// Created by Zeno on 2020/4/9.
//

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int left, int right)
{
    int key = v[left];
    while (left < right)
    {
        while (left < right && v[right] >= key)
        {
            right--;
        }
        if (left < right)
        {
            v[left++] = v[right];
        }

        while (left < right && v[left] < key)
        {
            left++;
        }
        if (left < right)
        {
            v[right++] = v[left];
        }
    }
    v[left] = key;
    return left;
}

int findTopK(vector<int> &v, int left, int right, int k)
{
    if (left >= right)
    {
        return -1;
    }

    int pos = partition(v, left, right);
    if (pos == k - 1)
    {
        return pos;
    }
    else if (pos > k - 1)
    {
        return findTopK(v, left, pos - 1, k);
    }
    else
    {
        return findTopK(v, pos + 1, right, k);
    }
}

int main()
{
    vector<int> v;
    for (int i = 0; i < 10000; i++)
    {
        v.push_back(rand() % 10000);
    }


    cout << v[findTopK(v, 0, v.size() - 1, 10)] << endl;

    for (int i = 0; i < 20; ++i)
    {
        cout << v[i] << ' ';
    }

    return 0;
}