class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int min_val=INT_MAX;
        int max_val=INT_MIN;
        bool falg=false;        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1])
                min_val=min(nums[i],min_val);
        }
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>nums[i+1])
                max_val=max(max_val,nums[i]);
        }
        int l=0;
        int r=nums.size()-1;
        while(l<nums.size()){
            if(nums[l]>min_val){
                break;
            }
            l++;
        }
        while(r>=0){
            if(nums[r]<max_val)
                break;
            r--;
        }
        if(r-l<0)
            return 0;
        return r-l+1;
    }
};