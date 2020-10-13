class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> copy=nums;
        int left_prod=nums[0];
        nums[0]=1;
        for(int i=1;i<nums.size();i++){
            int temp=nums[i];
            nums[i]=left_prod;
            left_prod*=temp;
        }

        int right_prod=copy[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            int temp=copy[i];
            nums[i]*=right_prod;
            right_prod*=temp;
        }
        return nums;
    }
};