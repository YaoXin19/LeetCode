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
        // 空间复杂度O(1), 时间O(nlogn)
        // merge sort(bottom up)
        /*
            4->2->1->3
            4->2  1->3
            4  2  1  3
        */
        if (!head || !head->next) return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(mid);
        return merge(l1, l2);
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(0);
        ListNode* ans = h;
        while (l1 && l2) {
            if (l1->val < l2->val) { h->next = l1; h = h->next; l1 = l1->next; }
            else { h->next = l2; h = h->next; l2 = l2->next; }
        }
        
        if (!l1) h->next = l2;
        if (!l2) h->next = l1;
        
        return ans->next;
    }
};