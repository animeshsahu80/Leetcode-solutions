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
    int numComponents(ListNode* head, vector<int>& G) {
        ListNode* iter=head;
        unordered_set<int>s (G.begin(),G.end());
        int count=0;
        while(iter){
            if((s.find(iter->val)!=s.end()) && (iter->next==NULL || s.find(iter->next->val)==s.end())){
                count++;
            }
            iter=iter->next;
        }
        return count;
    }
};