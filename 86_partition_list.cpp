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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1=new ListNode(0);
        ListNode* head2=new ListNode(0);
        ListNode* tail1=head1;
        ListNode* tail2=head2;
        ListNode* curr=head;
        while(curr){
            if(curr->val<x){
                tail1->next=curr;
                tail1=tail1->next;
            }
            else{
                tail2->next=curr;
                tail2=tail2->next;
            }
            curr=curr->next;
        }
        tail2->next=NULL;
        tail1->next=head2->next;
        return head1->next;
    }
};