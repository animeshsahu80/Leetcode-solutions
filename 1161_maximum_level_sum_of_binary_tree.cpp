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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int ans=INT_MIN;
        q.push(root);
        int ret=1;
        int level=1;
        while(q.size()){
            int n=q.size();
            int temp=0;
            while(n--){
                TreeNode *node=q.front();
                q.pop();
                temp=temp+node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(temp>=ans){
                ans=temp;
                ret=level;
            }
            level++;
        }
    return ret;
    
    
    }
};