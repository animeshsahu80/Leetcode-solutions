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
    int level=0;
    int maxDepth(Node* root) {
        if(root==NULL)
            return 0;
        levelordertrav(root);
        return level;
    }
    void levelordertrav(Node* root){
        queue<Node*> q;
        q.push(root);
        while(q.size()>0){
            level++;
            int size=q.size();
            while(size--){
                Node* temp=q.front();
                q.pop();
                for(Node* node : temp->children){
                    q.push(node);
                }
            }
        }
    }
};