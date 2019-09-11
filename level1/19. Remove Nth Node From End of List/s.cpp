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
    ListNode* removeNthFromEnd(ListNode* head, int n) {        
        ListNode* fast = head;
        int nn = n;
        while (nn) {
            fast = fast->next;
            --nn;
        }
        if (!fast) return head->next;
        
        ListNode* slow = head;
        fast = fast->next;
        while (fast) {
            slow = slow->next;
            fast = fast->next;            
        }
        
        // delete
        slow->next = slow->next->next;
        
        return head;
    }
};