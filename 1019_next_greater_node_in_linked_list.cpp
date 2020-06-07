/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=head;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        head=rev(head);
        stack<int> st;
        vector<int> vec;
        while(head){
            if(st.size()==0)
                vec.push_back(0);
            else if(st.size()>0 && st.top()>head->val){
                vec.push_back(st.top());
            }
            else if(st.size()>0 && st.top()<=head->val){
                while(st.size()>0&&st.top()<=head->val){
                    st.pop();
                }
                if(st.size()==0)
                    vec.push_back(0);
                else{
                    vec.push_back(st.top());
                }
            }
            
            st.push(head->val);
            head=head->next;
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};