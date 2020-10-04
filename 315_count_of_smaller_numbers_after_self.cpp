class Solution {
public:
    struct treenode{
        treenode* left;
        treenode* right;
        int val;
        int count=1;
    };
    int solver(int value,treenode* root){
        int ret=0;
        bool flag=false;
        treenode* temp=new treenode();
        temp->val=value;
        while(flag!=true){
            if(value>root->val){
                ret+=root->count;
                if(root->right==NULL){
                    root->right=temp;
                    flag=true;
                }
                else{
                    root=root->right;
                }
            }
            else{
                root->count++;
                if(root->left==NULL){
                    root->left=temp;
                    flag=true;
                }
                else{
                    root=root->left;
                }
            }
        }
        return ret;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        if(nums.size()==0)
            return res;
        res.push_back(0);
        int l=nums.size();
        treenode* root=new treenode();
        root->val=nums[l-1];
        for(int i=l-2;i>=0;i--){
            int ans=solver(nums[i],root);
            res.push_back(ans);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};