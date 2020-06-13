/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> out;
        if(root==NULL)
            return out;
        while(q.size()>0){
            int len=q.size();
            vector<int> vec;
            while(len--){
                Node* node=q.front();
                vec.push_back(node->val);
                for(Node* temp:node->children){
                    q.push(temp);
                    
                }
                q.pop();
            }
            out.push_back(vec);
        }
        return out;
    }
};