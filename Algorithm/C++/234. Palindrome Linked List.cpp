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

//**************************** 1/4/2019 *********************************
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        ListNode *slow = head, *fast = head->next;
        
        // Split the list into two parts
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        slow->next;
        
        // Reverse the second part of the list
        ListNode *prev = NULL, *temp;
        while (fast) {
            temp = fast->next;
            fast->next = prev;
            prev = fast;
            fast = temp;
        }
        
        // Compare two parts
        while (head && prev) {
            if (head->val != prev->val) return false;
            head = head->next;
            prev = prev->next;
        }
        
        return true;
    }
};

/********************** Older version **************************
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
************************************************************************/