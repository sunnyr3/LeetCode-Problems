/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:
Input: 1->1->1->2->3
Output: 2->3
*/

/*
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *dummy = new ListNode(0);
        ListNode *prev, *curr = head;
        dummy->next = head;
        prev = dummy;
        
        while (curr) {
            while (curr->next && prev->next->val == curr->next->val)
                curr = curr->next;
            
            if (prev->next == curr)
                prev = curr;
            else 
                prev->next = curr->next;
            
            curr = curr->next;
        }
        
        head = dummy->next;
        return head;
    }
};