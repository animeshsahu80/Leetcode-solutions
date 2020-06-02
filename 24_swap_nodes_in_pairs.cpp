/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
          if(head==NULL)
              return NULL;
        if(head->next==NULL)
            return head;
        ListNode* a=head;
        ListNode* b=head->next->next;
        head=head->next;
        head->next=a;
        a->next=swapPairs(b);
        return head;
    }
};