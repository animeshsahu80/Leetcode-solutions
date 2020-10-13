class Solution {
public:
    int solve(vector<int>& nums,int idx,vector<int>& dp){
        if(idx>=nums.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int op1=nums[idx]+solve(nums,idx+2,dp);
        int op2=solve(nums,idx+1,dp);
        return dp[idx]=max(op1,op2);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int ans=solve(nums,0,dp); 
        return ans;
    }
};