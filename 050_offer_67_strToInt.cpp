//
// Created by Zeno on 2020/4/23.
//
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int size = str.size();
        if (size == 0){
            return 0;
        }
        int i = 0;
        while (i < size && str[i] == ' '){
            i++;
        }
        if (i == size){
            return 0;
        }
        int isPositive = 1;
        if (str[i] == '+' || str[i] == '-'){
            if (str[i] == '-'){
                isPositive = -1;
            }
            i++;
        }
        if (i == size){
            return 0;
        }

        int res = 0;
        while (i < size && isdigit(str[i])){
            int num = str[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && num > 7)){
                return isPositive > 0 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + num;
            i++;
        }
        return res * isPositive;
    }
};

int main() {
    //cout << strToInt("2147483648") << endl;
    cout << std::isdigit('4') << endl;
    return 0;
}