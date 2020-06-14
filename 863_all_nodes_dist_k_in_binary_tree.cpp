/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;
    void dfs(TreeNode* root,TreeNode* parent){
        if(root==NULL)
            return;
        mp[root]=parent;
        dfs(root->left,root);
        dfs(root->right,root);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root,NULL);
        unordered_set<TreeNode*> seen;
        queue<TreeNode*> q;
        int level=0;
        q.push(target);
        seen.insert(target);
        while(level!=K){
            int n=q.size();
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && seen.find(node->left)==seen.end()){
                    q.push(node->left);
                    seen.insert(node->left);
                }
                if(node->right && seen.find(node->right)==seen.end()){
                    q.push(node->right);
                    seen.insert(node->right);
                }
                if(mp[node] && seen.find(mp[node])==seen.end()){
                    q.push(mp[node]);
                    seen.insert(mp[node]);
                }
            }
            
            level++;
        }
        vector<int> res;
        while(q.size()){
            TreeNode* temp=q.front();
            q.pop();
            res.push_back(temp->val);
        }
        return res;
    }
};