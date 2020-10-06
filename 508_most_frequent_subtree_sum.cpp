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
    int freq=0;
    map<int,int> mp;
    int dfs(TreeNode* root){
        if(root==NULL)
            return 0;
        int sum=root->val+ dfs(root->left) + dfs(root->right);
        mp[sum]++;
        freq=max(freq,mp[sum]);
    return sum;
    
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int num=dfs(root);
        vector<int> res;
        for(auto node:mp){
            if(node.second==freq){
                res.push_back(node.first);
            }
        }
        return res;
    }
};