//
// Created by Zeno on 2020/4/12.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int computeCurSum(vector<int> all_log, int left, int right, int N)
{
    int sum = 0;
    for (int i = left; i <= right; i++)
    {
        sum += pow(N, all_log[i]);
    }

    return sum;
}
vector<int> perfectNum(int R, int N)
{
    int max_log = log(R) / log(N);
    vector<int> all_log;
    vector<int> ret;

    if (R == 1)
    {
        ret.push_back(0);
        return ret;
    }
    if (R == N)
    {
        ret.push_back(1);
        return ret;
    }

    for (int i = 1; i <= max_log; i++)
    {
        all_log.push_back(i);
    }

    int left = 0;
    int right = 1;
    int curSum = 0;

    while (right <= max_log - 1 && left < right)
    {
        curSum = computeCurSum(all_log, left, right, N);
        if (curSum  == R)
        {
            for (int i = left; i <= right; i++)
            {
                ret.push_back(i + 1);
            }
            return ret;
        }

        if (curSum > R && left < right)
        {
            left++;
            continue;
        }

        if (curSum < R && right < max_log)
        {
            right++;
        }
    }
    return ret;
}

int main()
{
    //vector<int> all_log{1, 2, 3};
    //cout << computeCurSum(all_log, 0, 2, 3);
    vector<int> ret;
    ret = perfectNum(55, 100);

    for (int num : ret)
    {
        cout << num << ' ';
    }
    return 0;
}