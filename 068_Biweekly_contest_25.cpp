//
// Created by Zeno on 2020/5/2.
//
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

#if 0
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = INT_MIN;
        for (int n : candies) {
            max = std::max(max, n);
        }
        vector<bool> res;
        for (int n : candies) {
            if (n + extraCandies >= max) {
                res.push_back(true);
            }
            else {
                res.push_back(false);
            }
        }
        return res;
    }
};
#endif

#if 0
int makeMax(int num) {
    int tmp = num;
    int digit = 1;
    while (tmp / 10 > 0) {
        digit++;
        tmp /= 10;
    }
    int all_digits = digit;
    while (tmp == 9 && digit > 1) {
        digit--;
        tmp = num / (int) pow(10, digit - 1) % 10;
    }
    int res = 0;
    while (all_digits > 0) {
        int digit_num = num / (int) pow(10, all_digits - 1) % 10;
        if (digit_num == tmp) {
            res += 9 * (int) pow(10, all_digits - 1);
        } else {
            res += digit_num * (int) pow(10, all_digits) - 1;
        }
        all_digits--;
    }
    return res;
    //int tmp2 = num;
    //num += (9 - tmp) * (int) pow(10, digit - 1);
    //return num;
}

int makeMin(int num) {
    int tmp = num;
    int count_digits = 1;
    while (tmp / 10 > 0) {
        count_digits++;
        tmp /= 10;
    }
    if (tmp != 1) {
        num -= (tmp - 1) * (int) pow(10, count_digits - 1);
        return num;
    }
    count_digits--;
    tmp = num / (int) pow(10, count_digits - 1) % 10;
    while (tmp == 0 && count_digits > 1) {
        count_digits--;
        tmp = num / (int) pow(10, count_digits - 1) % 10;
    }
    num -= (tmp - 0) * (int) pow(10, count_digits - 1);
    return num;
}

int maxDiff(int num) {
    return makeMax(num) - makeMax(num);
}

int main() {
    cout << makeMax(955) << endl;
    return 0;
}
#endif

int length = 0;
string cur1;
string cur2;
vector<bool> visited;

vector<string> permuteUnique(string &str) {
    vector<string> res;
    sort(str.begin(), str.end());
    length = str.size();
    visited.resize(length, false);
    backtracking(str);
    return res;
}

void backtracking(string &cur, string &str) {
    if (cur.size() == length) {
        res.push_back(cur);
        return;
    } else {
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            if (i != 0 && !visited[i - 1] && nums[i] == nums[i - 1])
                continue;
            visited[i] = true;
            cur.push_back(nums[i]);
            backtracking(nums);
            visited[i] = false;
            cur.pop_back();
        }

    }
}

bool canBreak(string s1, string s2) {
    int size = s1.size();
    for (int i = 0; i < size; i++) {
        if (s1[i] < s2[i]) {
            return false;
        }
    }
    return true;
}

bool checkIfCanBreak(string s1, string s2) {

}