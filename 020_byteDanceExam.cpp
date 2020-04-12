//
// Created by Zeno on 2020/4/12.
//

#include <iostream>
#include <vector>

using namespace std;

bool helper(vector<int> &a, vector<int> &b)
{
    int diff = 0;
    bool flag = false;
    int i = 0;
    while(i < a.size())
    {
        if (a[i] == b[i])
        {
            i++;
        }
        else
        {
            if (flag)
                return false;
            while (a[i] != b[i])
            {
                if (diff == 0)
                {
                    diff = abs(a[i] - b[i]);
                    i++;
                }
                else
                {
                    if (diff == abs(a[i] - b[i]))
                    {
                        i++;
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            flag = true;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> v1;
        for(int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            v1.push_back(num);
        }
        vector<int> v2;
        for(int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            v2.push_back(num);
        }

        if (helper(v1, v2))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}