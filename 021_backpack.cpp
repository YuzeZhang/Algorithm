//
// Created by Zeno on 2020/4/12.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> w = {12, 5, 8, 9, 6};
vector<int> v = {9, 2, 4, 7, 8};
int C = 20;
int length = w.size();

vector<int> items;
vector<int> bestItems;
int curW = 0;
int curV = 0;
int bestV = 0;
int remainderV = 0;

int cnt = 0;

void func(int i)
{
    if (i == length)
    {
        cnt++;
        if (curV > bestV)
        {
            bestV = curV;
            bestItems = items;
        }
    } else
    {
        remainderV -= v[i];
        if (curW + w[i] < C)
        {
            items.push_back(w[i]);
            curW += w[i];
            curV += v[i];
            func(i + 1);
            items.pop_back();
            curW -= w[i];
            curV -= v[i];
        }

        if (curV + remainderV > bestV)
        {
            func(i + 1);
        }
        remainderV += v[i];
    }
}

int main()
{
    for (int val : v)
    {
        remainderV += val;
    }
    func(0);
    for (int num : bestItems)
    {
        cout << num << ' ';
    }
    cout << endl;
    cout << cnt;
    return 0;
}
