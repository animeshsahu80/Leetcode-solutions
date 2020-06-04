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



// 1->2->3->4->5
//       ^
// 1->2->3->null
// |  |
// 5->4->null

class Solution {
public:
    ListNode* reverse_list(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=head;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return ;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }        
        ListNode* a=head;
        ListNode* head2=reverse_list(slow->next);
        slow->next=NULL;
        ListNode* b=head2;
        ListNode* a_next=NULL;
        ListNode* b_next=NULL;
        while(a&&b){
            a_next=a->next;
            b_next=b->next;
            a->next=b;
            b->next=a_next;
            a=a_next;
            b=b_next;
        }
   
    }
};







