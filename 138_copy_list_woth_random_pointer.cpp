/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* copyRandomList(Node* head) { 
        if(head==NULL)
            return NULL;
        Node* curr=new Node(head->val);
        mp[head]=curr;
        curr->next=copyRandomList(head->next);
        curr->random=mp[head->random];
        return curr;
        
    }
};