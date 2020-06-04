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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* a=head;
        ListNode*b;
        while(a){
            b=head;
            while(a!=b){
                if(a->val<b->val){
                    int temp=a->val;
                    a->val=b->val;
                    b->val=temp;
          
                }
                      b=b->next;
            }
                a=a->next;
        }
        return head;
    }
};