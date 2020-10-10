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
    TreeNode* solve(vector<int>& nums,int left,int right){
        if(left>right)
            return NULL;
        int num=INT_MIN;
        int idx;
        for(int i=left;i<=right;i++){
            if(nums[i]>num){
                num=nums[i];
                idx=i;
            }
        }
        TreeNode* root=new TreeNode(nums[idx]);
        root->left=solve(nums,left,idx-1);
        root->right=solve(nums,idx+1,right);
        return root;
    
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root=solve(nums,0,nums.size()-1);
        return root;
    }
};