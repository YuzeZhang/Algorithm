//
// Created by Zeno on 2020/4/28.
//

class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        if (s2.empty()){
            if (s1.empty()){
                return -1;
            }
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }
private:
    stack<int> s1;
    stack<int> s2;
};