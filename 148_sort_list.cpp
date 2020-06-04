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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        while(fast&&fast->next){
            temp=slow;
            slow=slow->next;
            
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(slow);
        return merge(left,right);
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* ret=new ListNode(0);
        ListNode* ans=ret;
        while(l1&&l2){
            if(l1->val<l2->val){
                ans->next=l1;
                l1=l1->next;
            }
            else{
                ans->next=l2;
                l2=l2->next;
            }
            ans=ans->next;
        }
        if(l1){
            ans->next=l1;
            l1=l1->next;
        }
        if(l2){
            ans->next=l2;
            l2=l2->next;
        }
        return ret->next;
    }
};