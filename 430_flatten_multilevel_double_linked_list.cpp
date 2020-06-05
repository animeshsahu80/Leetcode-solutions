/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL)
            return NULL;
        Node* curr=head;
        stack<Node*> st;
        while(curr){
            if(curr->child){
                if(curr->next)
                st.push(curr->next);
                curr->next=curr->child;
                curr->next->prev=curr;
                curr->child=NULL;
            }
            // curr=curr->next;
            if(curr->next==NULL&& st.size()>0){
                Node *temp=st.top();
                st.pop();
                curr->next=temp;
                temp->prev=curr;
            }
            curr=curr->next;
        }
  
        return head;
    }
};