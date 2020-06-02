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
    ListNode* rotateRight(ListNode* head, int k) {
        int len=0;
        if(head==NULL)
            return NULL;
        ListNode* tail=head;
        while(tail->next){
            tail=tail->next;
            len++;
        }
        k=k%(len+1);
        if(k==0){
            return head;
        }
        int steps=len-k;
        tail->next=head;
        while(steps--){
            head=head->next;
        }
        ListNode* temp=head->next;
        head->next=NULL;
        return temp;
        
    }
};