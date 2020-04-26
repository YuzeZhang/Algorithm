//
// Created by Zeno on 2020/4/26.
//
#include <iostream>
#include <string>
using namespace std;

int count0(const string &s, int i) {
    int score = 0;
    for (int k = 0; k <= i; k++){
        if (s[k] == '0'){
            score++;
        }
    }
    return score;
}

int count1(const string &s, int j) {
    int score = 0;
    for (int k = j; k < s.size(); k++){
        if (s[k] == '1') {
            score++;
        }
    }
    return score;
}

int maxScore(string s) {
    int res = INT_MIN;
    for (int i = 0; i <= s.size() - 2; i++){
        int j = i + 1;
        res = max(res, count0(s, i) + count1(s, j));
    }
    return res;
}

int main() {
    cout << maxScore("00") << endl;
    return 0;
}