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
    int pred(TreeNode* root){
        root=root->left;
        while(root->right){
            root=root->right;
        }
        return root->val;
    }
    
    int succ(TreeNode* root){
        root=root->right;
        while(root->left){
            root=root->left;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return root;
        if(key>root->val)
            root->right=deleteNode(root->right,key);
        else if(key<root->val)
            root->left=deleteNode(root->left,key);
        else{
            if(root->right==NULL && root->left==NULL)
                root=NULL;
            else if(root->left){
                root->val=pred(root);
                root->left=deleteNode(root->laeft,root->val);
            }
            else{
                root->val=succ(root);
                root->right=deleteNode(root->right,root->val);
            }
        }
        return root;
    }
};