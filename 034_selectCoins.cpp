//
// Created by Zeno on 2020/4/17.
//

#include <iostream>
#include <algorithm>

using namespace std;

// 硬币种类：1 3 5
// 参数n表示面值，返回值表示组成面值n所需要的最少的硬币数量
const int n = 11;
int dp[n + 1] = {0}; // dp[n]：组成价值n需要的硬币最少数量

int func(int n){
    if (n <= 0)
    {
        dp[n] = 1;
        return -1;
    }
    if (dp[n] > 0){
        // dp[n] > 0 表示n这个子问题已经求解过了
        return dp[n];
    }
    if (n == 1 || n == 3 || n == 5){
        dp[n] = 1;
        return 1;
    }
    else if (n == 2 || n == 4){
        dp[n] = 2;
        return dp[n];
    }
    else{
        int n1 = func(n - 1) + 1;
        int n2 = func(n - 3) + 1;
        int n3 = func(n - 5) + 1;
        dp[n] = std::min({n1, n2, n3});
        return dp[n];
    }
}

int main()
{
    cout << func(0) << endl;
    return 0;
}
