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
    void solve(TreeNode* root, int sum,int curr,map<int,int>& mp,int& ans){
        if(root==NULL)
            return;
        curr+=root->val;
        if(mp.find(curr-sum)!=mp.end()){
            ans+=mp[curr-sum];
        }
        mp[curr]++;
        solve(root->left,sum,curr,mp,ans);
        solve(root->right,sum,curr,mp,ans);
        mp[curr]--;
        return;
    }
    int pathSum(TreeNode* root, int sum) {
        int ans=0;
        map<int,int> mp;
        mp[0]=1;
        solve(root,sum,0,mp,ans);
        return ans;
    }
};