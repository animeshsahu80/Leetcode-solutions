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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode(0);
        ListNode* iter=temp;
        int carry=0;
        while(l1 || l2){
            int a,b;
            if(l1)
                a=l1->val;
            else
                a=0;
            if(l2)
                b=l2->val;
            else
                b=0;
            int sum=a+b+carry;
            carry=sum/10;
            int digit=sum%10;
            ListNode* new_node=new ListNode(digit);
            iter->next=new_node;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
            iter=iter->next;
        }
        if(carry>0){
            ListNode* tmp=new ListNode(carry);
            iter->next=tmp;
            iter=iter->next;
        }
        return temp->next;
    }
};