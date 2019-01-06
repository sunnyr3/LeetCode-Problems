/*
You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1, v2;
        
        while (l1) {
            v1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            v2.push_back(l2->val);
            l2 = l2->next;
        }
        
        ListNode *head = NULL, *curr;
        int carry = 0, sum = 0, i = v1.size()-1, j = v2.size()-1;
        
        for (; i>=0 || j>= 0 || carry > 0; i--, j--) {
            sum = carry;
            if (i >= 0) {
                sum += v1[i];
            }
            if (j >= 0) {
                sum += v2[j];
            }
            
            carry = sum / 10;
            sum = sum % 10;
            
            curr = new ListNode(sum);
            curr->next = head;
            head = curr;
        }
        
        return head;
    }
};