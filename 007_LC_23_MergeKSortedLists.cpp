//
// Created by Zeno on 2020/4/9.
//

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* p1, ListNode* p2)
    {
        if (nullptr == p1)
        {
            return p2;
        }
        if (nullptr == p2)
        {
            return p1;
        }

        ListNode *head = nullptr, *cur = nullptr;
        if (p1->val < p2->val)
        {
            head = p1;
            cur = head;
            p1 = p1->next;
        }
        else
        {
            head = p2;
            cur = head;
            p2 = p2->next;
        }

        while (p1 && p2)
        {
            if (p1->val < p2->val)
            {
                cur->next = p1;
                p1 = p1->next;
                cur = cur->next;
            }
            else
            {
                cur->next = p2;
                p2 = p2->next;
                cur = cur->next;
            }
        }
        if (p1 != nullptr)
        {
            cur->next = p1;
        }
        else
        {
            cur->next = p2;
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right)
    {
        if (left >= right)
        {
            return lists[left];
        }

        int mid = (left + right) / 2;
        ListNode* p1 = mergeKLists(lists, left, mid);
        ListNode* p2 = mergeKLists(lists, mid + 1, right);

        return mergeTwoLists(p1, p2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
        {
            return nullptr;
        }
        return mergeKLists(lists, 0, lists.size() - 1);
    }
};