class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        int ans;
        int n=nums.size();
        if(nums.size()<=1){
            return 0;
        }
        while(l<=r){
            int m=l + (r-l)/2;
            if(m==0&&nums.size()>1){
                if(nums[0]>nums[1]){
                    ans=0;
                    return ans;
                }
                else
                    return 1;
            }
            else if(m==n-1&&n>1){
                if(nums[n-1]>nums[n-2]){
                    ans=n-1;
                    return ans;
                }
                else
                    return n-2;
            }
            else{
                if(nums[m]>nums[m-1]&& nums[m]>nums[m+1]){
                    ans=m;
                    return ans;
                }
                else if(nums[m]<nums[m+1]){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
        }
        return ans;
        
    }
};