/* Problem from: https://leetcode.com/problems/palindrome-linked-list/description/

Given a singly linked list, determine if it is a palindrome.

Example 1:
Input: 1->2
Output: false

Example 2:
Input: 1->2->2->1
Output: true;

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }
        
        int middle = ceil(len / 2.0);
        cur = head;
        while (middle) {
            cur = cur->next;
            middle--;
        }
        
        ListNode* prev = NULL;
        while (cur) {
            ListNode* nextTemp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextTemp;
        }
        
        ListNode* tail = prev;
        while (tail) {
            if (tail->val != head->val) return false;
            
            tail = tail->next;
            head = head->next;
        }
        return true;
    }
};