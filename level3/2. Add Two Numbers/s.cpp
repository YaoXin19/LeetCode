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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int k = 0;
        //int ans = 0;
        ListNode* head = new ListNode(0);
        ListNode* h = head;
        int last = 0;
        
        while (l1 && l2) {
            int temp = l1->val + l2->val + k;
            int quo = temp / 10;
            int rem = temp % 10;
            h->next = new ListNode(rem);
            h = h->next;
            k = (quo==0) ? 0 : 1;            
            l1 = l1->next;
            l2 = l2->next;            
        }
        
        while (l1) {
            int temp = l1->val + k;
            int quo = temp / 10;
            int rem = temp % 10;
            h->next = new ListNode(rem);
            h = h->next;
            k = (quo==0) ? 0 : 1;            
            l1 = l1->next;
        }
        
        while (l2) {
            int temp = l2->val + k;
            int quo = temp / 10;
            int rem = temp % 10;
            h->next = new ListNode(rem);
            h = h->next;
            k = (quo==0) ? 0 : 1;            
            l2 = l2->next;
        }
        
        if (k == 1) {
            h->next = new ListNode(1);            
        }
        
        h = head->next;
        delete head;
        return h;
    }
};