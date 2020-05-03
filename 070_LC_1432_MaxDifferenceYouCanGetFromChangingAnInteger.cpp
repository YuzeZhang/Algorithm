//
// Created by Zeno on 2020/5/3.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        int max = num, min = num;

        // Get all digits
        vector<int> digits;
        while (num) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());

        // Get max
        for (int digit : digits) {
            if (digit != 9) {
                max = replaceAllDigits(max, digit, 9);
                break;
            }
        }

        // Get min
        if (digits[0] != 1) {
            min = replaceAllDigits(min, digits[0], 1);
        } else {
            for (int i = 1; i < digits.size(); i++) {
                if (digits[i] != 0 && digits[i] != 1) {
                    // there must have digits[i] != 1, because digits[0] == 1, if you replace 1 in all digits, the first digit 1 will be replaced to 0
                    min = replaceAllDigits(min, digits[i], 0);
                    break;
                }
            }
        }
        return max - min;
    }
private:
    int replaceAllDigits(int num, int x, int y) {
        int position = 0;
        int res = 0;
        while (num) {
            if (num % 10 == x) {
                res += y * pow(10, position);
            } else {
                res += num % 10 * pow(10, position);
            }
            position++;
            num /= 10;
        }
        return res;
    }
};