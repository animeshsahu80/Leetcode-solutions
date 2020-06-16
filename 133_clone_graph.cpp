/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        unordered_map<int,Node*> mp;
        Node* first=new Node(node->val);
        mp[node->val]=first;
        queue<Node*> q;
        q.push(node);
        while(q.size()>0){
           Node* curr=q.front();
            q.pop();
           Node* clone=mp[curr->val];
           for(int i=0;i<curr->neighbors.size();i++){
               Node* temp=curr->neighbors[i];
               if(mp.find(temp->val)==mp.end()){
                   q.push(temp);
                   mp[temp->val]=new Node(temp->val);
               }
               clone->neighbors.push_back(mp[temp->val]);
           } 
        }
        return first;
    }
};  