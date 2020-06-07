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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> hm;
    
        ListNode* ret=new ListNode(0);
        ret->next=head;
        hm[0]=ret;
        ListNode* iter=head;
        int sum=0;
        while(iter){
            sum+=iter->val;
            if(hm.find(sum)==hm.end())
                hm[sum]=iter;
            else{
                ListNode*temp;
                temp=hm[sum];
                int temp_sum=sum;
                ListNode* node=temp->next;
                while(node!=iter){
                    temp_sum+=node->val;
                    hm.erase(temp_sum);
                    node=node->next;
                }
                temp->next=node->next;
            }
            iter=iter->next;
        }
        return ret->next;
        
    }
};