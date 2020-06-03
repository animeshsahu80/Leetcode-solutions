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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        return helper(head,NULL);
    }
    TreeNode* helper(ListNode* head,ListNode* end){
        if(end==head||(end&&end->next==head)){
            return NULL;
        } 
        ListNode* a=head;
        ListNode* b=head;
        while(b!=end&&b->next!=end){
            a=a->next;
            b=b->next->next;
        }
        TreeNode* root=new TreeNode(a->val);
    
        root->left=helper(head,a);
        root->right=helper(a->next,end);
        return root;
    }
};