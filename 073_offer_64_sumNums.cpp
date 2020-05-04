//
// Created by Zeno on 2020/5/5.
//

class Helper {
public:
    Helper() {
        m_n++;
        m_sum += m_n;
    }

    static void reset() {
        m_n = 0;
        m_sum = 0;
    }
    static int getSum() {
        return m_sum;
    }
private:
    static int m_n;
    static int m_sum;
};
int Helper::m_n = 0;
int Helper::m_sum = 0;
class Solution {
public:
    int sumNums(int n) {
        Helper::reset();
        Helper *p = new Helper[n];
        delete []p;
        p = nullptr;
        return Helper::getSum();
    }
};