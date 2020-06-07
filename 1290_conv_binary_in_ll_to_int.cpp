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
    int getDecimalValue(ListNode* head) {
        int l=0;
        ListNode* iter=head;
        while(iter){
            iter=iter->next;
            l++;
        }
        int num=0;
        for(int i=0;i<l;i++){
            num+=head->val*pow(2,l-1-i);
            head=head->next;
        }
        return num;
            
    }
};