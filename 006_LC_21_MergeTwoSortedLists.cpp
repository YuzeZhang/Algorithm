//
// Created by Zeno on 2020/4/9.
//

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (nullptr == l1)
            return l2;
        if (nullptr == l2)
            return l1;

        ListNode *head = nullptr, *cur = nullptr;
        if (l1->val < l2->val)
        {
            head = l1;
            cur = head;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            cur = head;
            l2 = l2->next;
        }

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if (l1 != nullptr)
        {
            cur->next = l1;
        }
        else
        {
            cur->next = l2;
        }
        return head;
    }
};