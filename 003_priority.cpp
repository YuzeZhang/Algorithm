//
// Created by Zeno on 2020/4/9.
//

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    vector<int> v;
    for (int i = 0; i < 10000; ++i)
    {
        v.push_back(rand() % 10000);
    }

    priority_queue<int, vector<int>, greater<>> minHeap;
    for(int i = 0; i < 10; ++i)
    {
        minHeap.push(v[i]);
    }

    for(int i = 10; i < 10000; ++i)
    {
        if (v[i] > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(v[i]);
        }
    }

    for(int i = 0; i < 10; ++i)
    {
        cout << minHeap.top() << ' ';
        minHeap.pop();
    }
    return 0;
}
