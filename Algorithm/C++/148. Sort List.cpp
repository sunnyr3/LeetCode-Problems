/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode *slow = head, *fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next = NULL;
        
        return merge(sortList(head), sortList(fast));
    }
    
private:
    ListNode* merge(ListNode *a, ListNode *b) {
        if (!a) return b;
        if (!b) return a;
        
        ListNode *n1 = a, *n2 = b, *res = NULL;
        
        if (n1->val <= n2->val) {
            res = n1;
            res->next = merge(n1->next, n2);
        }
        else {
            res = n2;
            res->next = merge(n1, n2->next);
        }
        
        return res;
    }
};