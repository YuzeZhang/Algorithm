//
// Created by Zeno on 2020/4/11.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        ret = recursiveCompute(input, 0, input.size() - 1);
        return ret;
    }
private:
    int computeThreeNum(int a, int b, char op)
    {
        switch (op)
        {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
        }
        return -1;
    }
    vector<int> recursiveCompute(string input, int left, int right)
    {
        vector<int> ret;

        // 以operator作为分割界限递归的计算每个operator左右两边的ret
        for (int i = left; i <= right; i++)
        {
            char op = input[i];
            if (op == '+' || op == '-' || op == '*')
            {
                vector<int> leftRet = recursiveCompute(input, left, i - 1);
                vector<int> rightRet = recursiveCompute(input, i + 1, right);

                for (int j = 0; j < leftRet.size(); j++)
                {
                    for (int k = 0; k < rightRet.size(); k++)
                    {
                        ret.push_back(computeThreeNum(leftRet[j], rightRet[k], input[i]));
                    }
                }
            }
        }

        if (ret.size() == 0)
        {
            int num = 0;
            for (int i = left; i <= right; i++)
            {
                num = num * 10 + input[i] - '0';
            }
            ret.push_back(num);
        }

        return ret;
    }
};