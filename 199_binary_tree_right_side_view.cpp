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
    vector<int> rightSideView(TreeNode* root) {
     queue<TreeNode*> q;
    
     q.push(root);
     vector<int> vec;
     if(root==NULL)
         return vec; 
    while(q.size()>0){
         int count=q.size();
         while(count){
             TreeNode* temp=q.front();
             q.pop();
             if(count==1)
                 vec.push_back(temp->val);
             if(temp->left)
                 q.push(temp->left);
             if(temp->right)
                 q.push(temp->right);
             count--;
         }
     }
     return vec;
    }
};