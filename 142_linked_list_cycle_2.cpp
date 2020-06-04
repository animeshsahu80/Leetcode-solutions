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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        int flag=0;
        while(slow&&fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag=1;
                break;
            }
        }
        if(flag==0)
            return NULL;
        else{
            ListNode* new_node=head;
            while(new_node!=slow){
                slow=slow->next;
                new_node=new_node->next;
            }
            return new_node;
        }
    }
};