//
// Created by Zeno on 2020/4/24.
//

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *prev = nullptr, *cur = head, *next = head->next;
        while (cur){
            cur->next = prev;
            prev = cur;
            cur = next;
            if (next)
                next = next->next;
        }
        return prev;
    }
};