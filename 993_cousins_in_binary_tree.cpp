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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            
            int len=q.size();
            int siblings=0;
            while(len--){
                int cousin=0;
                TreeNode* node=q.front();
                if(node->left){
                    q.push(node->left);
                    if(node->left->val==x || node->left->val==y){
                        cousin++;
                        siblings++;
                    }
                }
                if(node->right){
                    q.push(node->right);
                    if(node->right->val==x || node->right->val==y){
                        cousin++;
                        siblings++;
                    }
                }
                q.pop();
                if(cousin==2)
                    return false;
                
            }
            if(siblings==2)
                return true;
        }
        return false;
    }
};