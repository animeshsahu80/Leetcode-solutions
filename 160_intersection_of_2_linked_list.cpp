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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        if(headA==NULL||headB==NULL)
            return NULL;
        ListNode* iter1=headA;
        ListNode* iter2=headB;
        while(iter1){
            iter1=iter1->next;
            l1++;
        }
        while(iter2){
            iter2=iter2->next;
            l2++;
        }
        ListNode* iter;
        if(l1>l2){
            int num=l1-l2;
            iter=headA;
            while(num--){
                iter=iter->next;
            }
            while(iter!=headB){
                iter=iter->next;
                headB=headB->next;
            }
            return iter;
        }
        else{
            int num=l2-l1;
            iter=headB;
            while(num--){
                iter=iter->next;
            }
            while(iter!=headA){
                iter=iter->next;
                headA=headA->next;
            }
            return iter;
        }
        
    }
};