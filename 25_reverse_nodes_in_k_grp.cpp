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
    int count(ListNode* head){
        if(head==NULL)
            return 0;
        int n=0;
        while(head){
            head=head->next;
            n++;
        }
        return n;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *prev=NULL;
        ListNode *nxt,*curr=head;
        int num=count(head);
        if(num<k){
            return head;
        }
        int x=k;
        while(x--){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        if(head)
            head->next=reverseKGroup(nxt,k);
        return prev;
    }
};