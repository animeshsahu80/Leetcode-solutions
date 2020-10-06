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
    int sum=0;
    int solver(TreeNode* root){
        if(root==NULL)
            return 0;
        int l=solver(root->left);
        int r=solver(root->right);
        sum+= abs(l-r);
        return root->val+l+r;
    }
    int findTilt(TreeNode* root) {
        int ans=solver(root);
        return sum;
    }
};