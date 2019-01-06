/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.

Note:
Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *prev = NULL, *curr = head, *after = head->next;
        head = after;
        
        while (after) {
            // Swap
            curr->next = after->next;
            after->next = curr;
            if (prev){
                prev->next = after;
            }
            
            prev = curr;
            curr = curr->next;
            if (!curr) break;
            after = curr->next;
        }
        
        return head;
    }
};