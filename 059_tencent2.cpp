//
// Created by Zeno on 2020/4/26.
//

#include <iostream>
#include <cmath>
using namespace std;

int getLevel(int x) {
    for (int n = 1; ; n++){
        if (x >= pow(2, n - 1) && x < pow(2, n)){
            return n;
        }
    }
}

int getNode(int x, int k) {
    int level = getLevel(x);
    int diff = level - k;
    if (diff <= 0){
        return -1;
    }
    int n = x;
    for (int i = 0; i < diff; i++){
        n = (n - 1 - 1) / 2 + 1;
    }
    return n;
}

int main() {
    int Q;
    while (cin >> Q){
        for (int i = 0; i < Q; i++){
            int x, k;
            cin >> x;
            cin >> k;
            cout << getNode(x, k) << endl;
        }
    }
    return 0;
}
