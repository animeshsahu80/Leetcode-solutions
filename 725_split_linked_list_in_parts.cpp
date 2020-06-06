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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
     int count=0;
     ListNode* iter=root;
     while(iter){
        count++;
         iter=iter->next;
     }
    iter=root;
    int a=count/k;
    int b=count%k;
    vector<ListNode*> out;
    while(iter){
        ListNode* prev=NULL;
        out.push_back(iter);
        int i=a;
        while(i--){
            prev=iter;
            iter=iter->next;
        }
        if(b){
            b--;
            prev=iter;
            iter=iter->next;
        }
        prev->next=NULL;
       
    }    
        if(out.size()<k){
            while(k-out.size()){
                ListNode* p;
                out.push_back(NULL);
            }
        }
     return out;
    }
};