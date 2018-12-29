/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *node = dummy;
        while (--n && --m) {
            node = node->next;
        }

        ListNode *tail = node->next, *pullNode = tail->next;
        while (n--) {
            tail->next = pullNode->next;
            pullNode->next = node->next;
            node->next = pullNode;
            pullNode = tail->next;
        }

        head = dummy->next;
        return head;
    }
};