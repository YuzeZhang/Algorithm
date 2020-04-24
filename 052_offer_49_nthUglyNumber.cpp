//
// Created by Zeno on 2020/4/24.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Ugly {
public:
    int *nums = new int[1690]();
    Ugly() {
        nums[0] = 1;
        int ugly, i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < 1690; i++){
            ugly = std::min({nums[i2] * 2, nums[i3] * 3, nums[i5] * 5});
            nums[i] = ugly;

            if (nums[i2] * 2 == ugly) i2++;
            if (nums[i3] * 3 == ugly) i3++;
            if (nums[i5] * 5 == ugly) i5++;
        }
    }
};
class Solution {
public:
    static Ugly* u;
    int nthUglyNumber(int n) {
        return u->nums[n - 1];
    }
};
Ugly *Solution::u = new Ugly();

int main(){
    int *nums = new int[100]();
    cout << nthUglyNumber(10) << endl;
    return 0;
}
