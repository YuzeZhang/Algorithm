//
// Created by Zeno on 2020/5/3.
//

#ifdef __LOCAL__
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <deque>
#else
#include<bits/stdc++.h>
#endif

using namespace std;

const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;

#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;


using namespace std;

#if 0
string destCity(vector<vector<string>>& paths) {
    unordered_map<string, bool> mp;
    for (auto v : paths) {
        mp[v[0]] = false;
        if (mp.count(v[1])) {
            if (mp[v[1]] == false) {
                continue;
            }
        } else {
            mp[v[1]] = true;
        }
    }
    for (auto item : mp) {
        if (item.second == true) {
            return item.first;
        }
    }
    return "";
}

int main() {
    cout << destCity({{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}}) << endl;
    return 0;
}

#endif

#if 0
bool kLengthApart(vector<int>& nums, int k) {
    int prev_one = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            if (prev_one == -1) {
                prev_one = i;
            } else {
                if (i - prev_one <= k) {
                    return false;
                } else {
                    prev_one = i;
                }
            }
        }
    }
    return true;
}
#endif
class MonotonicQueue {
private:
    deque<int> data;
public:
    void push1(int x) {
        while (!data.empty() && data.back() < x) {
            data.pop_back();
        }
        data.push_back(x);
    }
    void push2(int x) {
        while (!data.empty() && data.back() > x) {
            data.pop_back();
        }
        data.push_back(x);
    }
    int front () {
        return data.front();
    }
    void pop(int x) {
        if (!data.empty() && data.front() == x) {
            data.pop_front();
        }
    }
};
int longestSubarray(vector<int>& nums, int limit) {
    int right = 0;
    int left = 0;
    int res = INT_MIN;
    MonotonicQueue maxQue;
    MonotonicQueue minQue;

    while (right < nums.size()) {
        maxQue.push1(nums[right]);
        minQue.push2(nums[right]);
        while (maxQue.front() - minQue.front() > limit) {
            maxQue.pop(nums[left]);
            minQue.pop(nums[left]);
            left++;
        }
        res = std::max(res, right - left + 1);
        right++;
    }
    return res;
}

int main() {
    vector<int> v = {8, 2, 4, 7};
    cout << longestSubarray(v, 4) << endl;
}