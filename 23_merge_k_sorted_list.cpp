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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto l:lists){
            while(l!=NULL){
                q.push(l->val);
                l=l->next;
            }               
        }
        ListNode* dummy=new ListNode(0);
        ListNode* iter=dummy;
        while(q.size()>0){
            ListNode* temp=new ListNode(q.top());
            iter->next=temp;
            iter=iter->next;
            q.pop();
        }
        return dummy->next;
    }
};