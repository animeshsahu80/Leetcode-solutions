class Solution {
public:
    
    void backtrack(vector<vector<int>>& res,vector<int>& vec,vector<bool>& used,vector<int>& nums){
        if(vec.size()==nums.size()){
            res.push_back(vec);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]==true)
                continue;
            used[i]=true;
            vec.push_back(nums[i]);
            backtrack(res,vec,used,nums);
            vec.pop_back();
            used[i]=false;
        }
         return;   
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<bool> used(n,false);
        vector<int> vec;
        vector<vector<int>> res;
        if(nums.size()==0)
                return res;
        backtrack(res,vec,used,nums);
        return res;
    }
};


