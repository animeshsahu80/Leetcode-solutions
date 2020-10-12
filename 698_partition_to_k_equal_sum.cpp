class Solution {
public:
    bool solve(vector<int>& nums,int idx,int currsum,int k,int sum,vector<bool>& used){
        if(k==1)
            return true;
        if(currsum==sum)
            return solve(nums,0,0,k-1,sum,used);
        for(int i=idx;i<nums.size();i++){
            if(used[i]==false&& currsum+nums[i]<=sum){
                used[i]=true;
                if(solve(nums,i+1,currsum+nums[i],k,sum,used))
                    return true;
                used[i]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto val:nums){
            sum+=val;
        }
        if(k==0 || sum%k!=0)
            return false;
        sum=sum/k;
        vector<bool> used(nums.size(),false);
        return solve(nums,0,0,k,sum,used);
    }
};