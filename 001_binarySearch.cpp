//
// Created by Zeno on 2020/4/8.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(const vector<int> &v, int key, int start, int end)
{
    if (start > end)
    {
        return false;
    }
    int mid = (start + end) / 2;
    if (v[mid] == key)
    {
        return true;
    }
    else if (v[mid] > key)
    {
        return binarySearch(v, key, start, mid - 1);
    }
    else
    {
        return binarySearch(v, key, mid + 1, end);
    }
}

int main()
{
    vector<int> v;
    for(int i = 0; i < 100; i++)
    {
        v.push_back(rand() % 100);
    }

    sort(v.begin(), v.end());

    cout << boolalpha << binarySearch(v, 99, 0, v.size() - 1)<< endl;

    for (auto num : v)
    {
        cout << num << ' ';
    }
    return 0;
}
