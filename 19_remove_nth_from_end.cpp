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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* first=head;
        ListNode* sec=head;
        if(head==NULL|| head->next==NULL)
            return NULL;
        while(n){
            
            sec=sec->next;
            n--;
        }
        if(sec==NULL)
            return first->next;
        while(sec->next){
            sec=sec->next;
            first=first->next;
        }
        first->next=first->next->next;
        return temp;
    }
};