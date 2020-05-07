//
// Created by Zeno on 2020/5/7.
//

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    // 使用一个辅助栈，若辅助栈为空或栈顶元素不为popped[i]时，按顺序将pushed中的元素入栈，若pushed遍历完也没找到popped[i]，则return false
    // 若栈顶元素为popped[i]，则出栈、i++
    stack<int> st;
    int i;
    int j = 0;
    for (i = 0; i < popped.size(); i++) {
        if (!st.empty() && st.top() == popped[i]) {
            st.pop();
            continue;
        }
        for (; j < pushed.size(); j++) {
            st.push(pushed[j]);
            if (st.top() == popped[i]) {
                j++;
                st.pop();
                break;
            }
        }
    }
    if (st.empty() && i == pushed.size() && j == popped.size()) {
        return true;
    }
    return false;
}