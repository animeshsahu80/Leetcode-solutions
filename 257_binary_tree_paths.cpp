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
  
    vector<string> out;
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        if(root==NULL)
            return out;
        helper(root,s);
        
        return out;
    }
    void helper(TreeNode* root,string s){
        s=s+ to_string(root->val)+"->";
        if(root->left==NULL&&root->right==NULL){
            s.pop_back();
            s.pop_back();
            out.push_back(s);
            return;
        }
        
        if(root->left)
            helper(root->left,s);
        if(root->right)
            helper(root->right,s);
       // vec.pop_back();
    }
};