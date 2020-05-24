/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *newHead = nullptr;
        if (nullptr == l1)
            return l2;
        if (nullptr == l2)
            return l1;
        if (l1->val <= l2->val) {
            newHead = l1;
            newHead->next = mergeTwoLists(newHead->next, l2);
        } else {
            newHead = l2;
            newHead->next = mergeTwoLists(newHead->next, l1);
        }
        return newHead;
    }
};