/* Problem from: https://leetcode.com/problems/reverse-linked-list/description/

Reverse a singly linked list.

Example:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    /*
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    ListNode* reverseList_iterative(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    /*
     * Time complexity: O(n)
     * Space complexity: O(n). The extra space comes from implicit stack space due to recursion.
     */
    ListNode* reverseList_recursive(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* res = reverseList_recursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return res;
    }
};