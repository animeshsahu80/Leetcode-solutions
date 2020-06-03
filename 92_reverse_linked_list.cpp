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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL)
            return NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(m>1){
            prev=curr;
            curr=curr->next;
            m--;
            n--;
        }
        ListNode* temp1=prev;
        ListNode* temp2=curr;
        ListNode* nxt=curr;
        while(n--){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        if(temp1)
        temp1->next=prev;
        else
            head=prev;

        temp2->next=curr;
        return head;
    }
};