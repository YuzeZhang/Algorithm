//
// Created by Zeno on 2020/4/26.
//
#include <iostream>
#include <stack>

using namespace std;

class Queue {
public:
    void add (int x){
        stack1.push(x);
    }
    void poll() {
        if (stack2.size() <= 0){
            while (stack1.size() > 0){
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        }
        stack2.pop();
    }
    int peek() {
        if (stack2.size() <= 0){
            while (stack1.size() > 0){
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        }
        int head = stack2.top();
        return head;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    int N;
    while (cin >> N){
        Queue que;
        for (int i = 0; i < N; i++){
            string op;
            cin >> op;
            if (op == "add"){
                int x;
                cin >> x;
                que.add(x);
            } else if (op == "poll") {
                que.poll();
            } else if (op == "peek") {
                cout << que.peek() << endl;
            }
        }
    }
    return 0;
}