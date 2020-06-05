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
    ListNode* reverse_list(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt=head;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>a;
        vector<int>b;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        int p=0,q=0;
        while(l1){
            a.push_back(l1->val);
            l1=l1->next;
            p++;
        }
        while(l2){
            b.push_back(l2->val);
            l2=l2->next;
            q++;
        }
        int num;
        p=a.size()-1;
        q=b.size()-1;
        ListNode* node=new ListNode(0);
        ListNode* iter=node;
        ListNode* ret;
        int c=0;
        while((p>=0||q>=0)|| c>0){
                int m,n;
            if(p<0)
                m=0;
            else
                m=a[p];
            if(q<0)
                n=0;
            else
                n=b[q];
            int val;
            val=c+m+n;
            ListNode* temp=new ListNode(val%10);
            iter->next=temp;
            c=val/10;
            iter=iter->next;
            p--;
            q--;
        }
        node->next=reverse_list(node->next);
        return node->next;
    }
};