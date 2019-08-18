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
    void reorderList(ListNode* head) {
        
        if (!head) return;
        // 求中点
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        // 反转
        ListNode* list2 = reverse(mid);
        ListNode* list1 = head;

        // 合并
        ListNode* merged = merge(list1, list2);
        head->next = merged->next;
    }
    
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
      ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* h = new ListNode(0);
        ListNode* ans = h;
        while (l1 && l2) {
          h->next = l1;
          h = h->next;
          l1 = l1->next;
          h->next = l2;
          h = h->next;
          l2 = l2->next;

          //l1 = l1->next;
        }

        if (!l1) h->next = l2;
        if (!l2) h->next = l1;

        return ans->next;
      }
};