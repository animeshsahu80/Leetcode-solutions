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
    vector<int> largestValues(TreeNode* root) {
       vector<int> vec;
        if(root==NULL)
            return vec;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int len=q.size();
            int ans=INT_MIN;
            while(len--){
                TreeNode* node=q.front();
                q.pop();
                if(node->val>=ans)
                    ans=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            vec.push_back(ans);
        }
        return vec;
    }
};