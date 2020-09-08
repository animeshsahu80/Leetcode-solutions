class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp=nums[0];
        
        for(int i=1;i<nums.size();i++){
            temp^=nums[i];
        }
        int idx=0;
        for(int i=0;i<=31;i++){
            if((temp>>i)&1){
                idx=i;
                break;
            }
        }
        int x=1<<idx;
        //int x=temp&(-temp);
        vector<int> res(2);
        for(int i=0;i<nums.size();i++){
            if((nums[i]&x)==0)
                res[0]^=nums[i];
            else
                res[1]^=nums[i];
        }
        return res;
    }
};