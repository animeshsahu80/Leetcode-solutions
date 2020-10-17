class Solution {
public:

    int maxProduct(vector<int>& nums) {
            int ans=nums[0];
            int max_so_far=nums[0];
            int min_so_far=nums[0];
            for(int i=1;i<nums.size();i++){
                int temp=max_so_far;
                max_so_far=max(max(nums[i],nums[i]*max_so_far),nums[i]*min_so_far);
                min_so_far=min(min(nums[i],nums[i]*min_so_far),nums[i]*temp);
                if(max_so_far>ans){
                    ans=max_so_far;
                }
            }
        return ans;
    }
};