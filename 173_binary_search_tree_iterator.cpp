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
class BSTIterator {
public:
    stack <TreeNode*> st;
    BSTIterator(TreeNode* root) {
        push_node(root);    
    }
    void push_node(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
        
    }
    /** @return the next smallest number */
    int next() {
        TreeNode* curr=st.top();
        st.pop();
        int ans=curr->val;
   
        push_node(curr->right);
        
        return ans;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(st.size()>0)
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */